#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;
#include "selectionsort.h"

int main() {
    vector<int> v;
    for (int i = 9; i >= 0; --i) v.push_back(i); //Populating vector
    cout << "Pre:  "; printObj(v);
    selectionSort(v);
    cout << "Post: "; printObj(v);
    list<int> l;
    cout << "Pre:  "; printObj(l);
    selectionSort(l);
    cout << "Post: "; printObj(l);
    list<pair<int, int>> p;
    int moves = 0;
    p.push_back(make_pair(1, 2));
    p.push_back(make_pair(3, -1));
    p.push_back(make_pair(-1, 3));
    p.push_back(make_pair(0, 0));
    p.push_back(make_pair(2, 3));
    p.push_back(make_pair(1, 2));
    p.push_back(make_pair(1, -2));
    p.push_back(make_pair(8, 10));
    cout << "Pre:  "; printPair(p);
    moves = selectionSort(p);
    cout << "Post: "; printPair(p);
    cout << "0 copies and " << moves << " moves." << endl;
    p.clear();
    p.push_back(make_pair(10, 2));
    p.push_back(make_pair(-3, -1));
    p.push_back(make_pair(-8, 0));
    p.push_back(make_pair(1, 1));
    p.push_back(make_pair(1, 1));
    p.push_back(make_pair(0, 0));
    p.push_back(make_pair(10, 2));
    p.push_back(make_pair(5, 5));
    p.push_back(make_pair(5, -5));
    p.push_back(make_pair(0, 0));
    p.push_back(make_pair(10, 2));
    cout << "Pre:  "; printPair(p);
    moves = selectionSort(p);
    cout << "Post: "; printPair(p);
    cout << "0 copies and " << moves << " moves." << endl;
    p.clear();
    populateList(p);
    cout << "Pre:  "; printPair(p);
    moves = selectionSort(p);
    cout << "Post: "; printPair(p);
    cout << "0 copies and " << moves << " moves." << endl;
    p.clear();
    return 0;
}