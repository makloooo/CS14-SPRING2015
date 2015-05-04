#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void PrePrimesRec(int m, int n, int k) {
    if (m + n <= k) {
        cout << m << ' ' << n << endl;
        PrePrimesRec(2*m - n, m, k);
        PrePrimesRec(2*m + n, m, k);
        PrePrimesRec(m + 2*n, n, k);
    }
    return;
}

void PrePrimes(int k) {
    PrePrimesRec(2, 1, k);
    PrePrimesRec(3, 1, k);
    return;
}

void PostPrimesRec(int m, int n, int k) {
    if (m + n <= k) {
        PostPrimesRec(2*m - n, m, k);
        PostPrimesRec(2*m + n, m, k);
        PostPrimesRec(m + 2*n, n, k);
        cout << m << ' ' << n << endl;
    }
    return;
}

void PostPrimes(int k) {
    PostPrimesRec(2, 1, k);
    PostPrimesRec(3, 1, k);
    return;
}

void dumpStack(priority_queue<pair<int, int>>& entryStack) {
    if (entryStack.empty()) return;
    pair<int, int> values = make_pair(get<0>(entryStack.top()), get<1>(entryStack.top()));
    entryStack.pop();
    dumpStack(entryStack);
    cout << get<0>(values) << ' ' << get<1>(values) << endl;
    return;
}

void ScanSort(int m, int n, int k, priority_queue<pair<int, int>>& target) {
    pair<int, int> entry;
    if (m + n <= k) {
        if (m + n == k) {
            entry = make_pair(m, n);
            target.push(entry);
        }
        ScanSort(2*m - n, m, k, target);
        ScanSort(2*m + n, m, k, target);
        ScanSort(m + 2*n, n, k, target);
    }
    return;
}

void SortedPrimes(int k) {
    typedef priority_queue<pair<int, int>> primeQueue;
    static primeQueue entryStack;
    pair<int, int> entry;
    
    entry = make_pair(2, 1);
    entryStack.push(entry);
    entry = make_pair(3, 1);
    entryStack.push(entry);
    dumpStack(entryStack);
    
    for (int i = 5; i <= k; ++i) {
        ScanSort(2, 1, i, entryStack);
        ScanSort(3, 1, i, entryStack);
        dumpStack(entryStack);
    }
    
    // All of this unneccessary breadth first traversal
    // queue<pair<int,int>> currStack;
    // queue<pair<int,int>> tempQueue;
    // pair<int, int> entry2;
    
    // entry = make_pair(2, 1);
    // entryStack.push(entry);
    // currStack.push(entry);
    // entry = make_pair(3, 1);
    // entryStack.push(entry);
    // currStack.push(entry);
    
    // while(!entryStack.empty()) {
    //     dumpStack(entryStack); // This empties the stack
    //     while(!currStack.empty()) {
    //         if (2 * get<0>(currStack.front()) - get<1>(currStack.front()) + get<0>(currStack.front()) <= k) {
    //             entry = make_pair(2 * get<0>(currStack.front()) - get<1>(currStack.front()), get<0>(currStack.front())); // 2m + n, m
    //             entryStack.push(entry);
    //             tempQueue.push(entry);
    //         }
    //         if (2 * get<0>(currStack.front()) + get<1>(currStack.front()) + get<0>(currStack.front()) <= k) {
    //             entry = make_pair(2 * get<0>(currStack.front()) + get<1>(currStack.front()), get<0>(currStack.front()));
    //             entryStack.push(entry);
    //             tempQueue.push(entry);
    //         }
    //         if (get<0>(currStack.front()) + 2 * get<1>(currStack.front()) + get<1>(currStack.front()) <= k) {
    //             entry = make_pair(get<0>(currStack.front()) + 2 * get<1>(currStack.front()), get<1>(currStack.front()));
    //             entryStack.push(entry);
    //             tempQueue.push(entry);
    //         }
    //         currStack.pop();
    //     }
        
    //     while(!tempQueue.empty()) {
    //         currStack.push(tempQueue.front());
    //         tempQueue.pop();
    //     }
    // }
    return;
}