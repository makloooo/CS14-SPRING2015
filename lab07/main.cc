// Name: Mark Lieu
// Date: 5/18/15
// SID: 861148602
/* Approach: 
    Create a class that contains run data. Fill it up during the main function
    loop, then average each run. Dump the data into the readme file via
    appending and start the loop again for the next value of 'n' */


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
    vector<string>::iterator it;
    fstream inFS;
    
    clock_t runtime;
    clock_t ticks;
    float Ftime = 0.0;
    
    runData r;
    
    inFS.open("output.txt", ios::out | ios::trunc);
    inFS.close();
    
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
    for (int n = 5000; n <= 50000; n += 5000) {
        random_shuffle(word_bank.begin(), word_bank.end());
        for (int i = 0; i < 10; ++i) {
            tree.clear();
            hash.clear();
            
            /*----------Clocking Tree insertion time----------*/
            runtime = clock();
            for (int i = 0; i < n; ++i) {
                tree.insert(word_bank.at(i)); // Using *it to avoid lookup in vector time.
            }
            ticks = clock() - runtime;
            r.treeIns.push_back((static_cast<float>(ticks) / CLOCKS_PER_SEC)*1000);
            /*----------Clocking Tree insertion time----------*/
            
            /*----------Clocking tree find time----------*/
            Ftime = 0.0;
            ticks = 0;
            for (int i = 0; i < n; ++i) { 
                runtime = clock();
                tree.find(word_bank.at(i));
                ticks += clock() - runtime;
            }
            Ftime = (static_cast<float>(ticks)/CLOCKS_PER_SEC)*1000;
            r.treeFind.push_back(Ftime / n);
            /*----------Clocking tree find time----------*/
            
            /*----------Clocking Hash insertion time----------*/
            ticks = 0;
            runtime = clock();
            for (int i = 0; i < n; ++i) {
                hash.insert(word_bank.at(i));
            }
            ticks += clock() - runtime;
            r.hashIns.push_back((static_cast<float>(ticks) / CLOCKS_PER_SEC)*1000);
            /*----------Clocking Hash insertion time----------*/
            
            /*----------Clocking Hash Find Time----------*/
            Ftime = 0.0;
            ticks = 0;
            for (int i = 0; i < n; ++i) { 
                runtime = clock();
                hash.find(word_bank.at(i));
                ticks += clock() - runtime;
            }
            Ftime = (static_cast<float>(ticks) / CLOCKS_PER_SEC)*1000;
            r.hashFind.push_back(Ftime / n);
            /*----------Clocking Hash Find Time----------*/
        }
        r.dumpData("output.txt", n);
    }
    
    inFS.close();
    
    return 0;
}