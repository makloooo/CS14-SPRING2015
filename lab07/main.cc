#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class runData {
    public:
        vector<float> treeIns;
        vector<float> hashIns;
        vector<float> treeFind;
        vector<float> hashFind;
        
        void clear() {
            treeIns.clear();
            hashIns.clear();
            treeFind.clear();
            hashFind.clear();
            return;
        }
        void dumpData(string oFile, int n) {
            cout << "DEBUG - Dumping data of n valued at " << n << endl;
            ofstream inFS;
            inFS.open(oFile.c_str(), ios::app);
            if (!inFS.is_open()) {
                cout << "Error opening 'output.txt'. Exiting..." << endl;
                exit(-1);
            }
            
            // Fetch averages
            float avgtreeIns = 0.0;
            float avghashIns = 0.0;
            float avgtreeFind = 0.0;
            float avghashFind = 0.0;
            
            for (int i = 0; i < 10; ++i) {
                avgtreeIns += treeIns.at(i);
                avghashIns += hashIns.at(i);
                avgtreeFind += treeFind.at(i);
                avghashFind += hashFind.at(i);
            }
            
            avgtreeIns /= 10;
            avghashIns /= 10;
            avgtreeFind /= 10;
            avghashFind /= 10;
            
            // Write statement
            inFS << n << ' ' << avgtreeIns << ' ' << avghashIns << ' ' << avgtreeFind << ' ' << avghashFind << endl;
            
            clear(); // Automatic clear on dump.
            inFS.close();
            return;
        }
};

int main() {
    set<string> tree;
    unordered_set<string> hash;
    vector<string> word_bank;
    fstream inFS;
    
    runData r;
    
    inFS.open("words.txt"); // Reading in file to vector then shuffling it
    if (!inFS.is_open()) {
        cout << "Error opening 'words.txt'. Exiting..." << endl;
        exit(-1);
    }
    string data;
    while (!inFS.eof()) {
        inFS >> data;
        word_bank.push_back(data);
    }
    inFS.close();
    
    // int n = 0;
    // cout << "Enter your value of n: "; cin >> n;
    clock_t runtime;
    for (int n = 5000; n <= 50000; n += 5000) {
        random_shuffle(word_bank.begin(), word_bank.end());
        for (int i = 0; i < 10; ++i) {
            tree.clear();
            hash.clear();
            
            runtime = clock(); // Clocking tree insertion time
            for (int i = 0; i < n; ++i) { // Insertion time
                tree.insert(word_bank.at(i));
            }
            clock_t treeClicks = clock() - runtime;
            r.treeIns.push_back((static_cast<float>(treeClicks) / CLOCKS_PER_SEC)*1000);
            
            float Ftime = 0.0; // Clocking tree find time
            for (int i = 0; i < n; ++i) { 
                runtime = clock();
                tree.find(word_bank.at(i));
                treeClicks = clock() - runtime;
                Ftime += (static_cast<float>(treeClicks)/CLOCKS_PER_SEC)*1000;
            }
            //cout << "DEBUG - Tree Ftime: " << Ftime << endl;
            r.treeFind.push_back(Ftime / n);
            
            runtime = clock();
            for (int i = 0; i < n; ++i) {
                hash.insert(word_bank.at(i));
            }
            clock_t hashClicks = clock() - runtime;
            r.hashIns.push_back((static_cast<float>(hashClicks) / CLOCKS_PER_SEC)*1000);
            
            Ftime = 0.0;
            for (int i = 0; i < n; ++i) { 
                runtime = clock();
                hash.find(word_bank.at(i));
                hashClicks = clock() - runtime;
                Ftime += (static_cast<float>(hashClicks) / CLOCKS_PER_SEC)*1000;
            }
            // cout << "Hash Ftime: " << Ftime << endl;
            r.hashFind.push_back(Ftime / n);
            // char cont;
            // cout << "Continue (y/n)? "; cin >> cont;
            // if (cont != 'y') exit(0);
        }
        r.dumpData("output.txt", n);
    }
    
    inFS.close();
    
    return 0;
}