#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename L>
void populateList(L& m) {
    pair<int, int> p;
    int n = 10;
    for (int i = 0; i < 10; ++i) {
        p = make_pair(i, n);
        m.push_back(p);
        --n;
    }
}

template<typename L>
void printObj(L v) {
    typename L::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

template<typename L>
void printPair(L v) {
    typename L::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << '(' << it->first << ", " << it->second << ") ";
    }
    cout << endl;
}

template<typename L>
int selectionSort(L &l) {
    int moves = 0;
    typename L::iterator it;
    typename L::iterator it2;
    typename L::iterator minLoc;
    bool order = false;
    for (it = l.begin(); it != l.end(); ++it) {
        order = false;
        minLoc = it;
        for (it2 = it; it2 != l.end(); ++it2) {
            if (*it2 < *minLoc) {
                order = true;
                minLoc = it2;
            }
        }
        // printObj(l);
        // cout << "MinLoc: " << *minLoc << endl;
        if (order) {
            swap(*minLoc, *it);
            moves += 3;
        }
    }
    
    return moves;
}

#endif