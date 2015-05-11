#include <iostream>
using namespace std;
#include "lab5.h"

int main() {
    
    map<int, int> m; 
    
    BST<int> tree;
    tree.insert(50);
    tree.insert(60);
    tree.insert(70);
    tree.insert(20);
    tree.insert(10);
    tree.insert(40);
    tree.insert(35);
    tree.insert(45);
    int arr[1000];
    cout << "Testcase1" << endl;
    cout << "Part1" << endl;
    tree.displayMinCover();
    cout << "Part2" << endl;
    tree.findSumPath(tree.getRoot(), 80, arr);
    cout << "Part3" << endl;
    tree.vertSum(tree.getRoot(), 0, m);
    
    map<int, int> m2;
    BST<int> tree2;
    tree2.insert(30);
    tree2.insert(15);
    tree2.insert(25);
    tree2.insert(20);
    tree2.insert(14);
    tree2.insert(11);
    tree2.insert(12);
    tree2.insert(13);
    tree2.insert(10);
    tree2.insert(7);
    tree2.insert(5);
    tree2.insert(3);
    tree2.insert(8);
    tree2.insert(31);
    tree2.insert(34);
    cout << "\nTestcase2" << endl;
    cout << "Part1" << endl;
    tree2.displayMinCover();
    cout << "Part2" << endl;
    tree2.findSumPath(tree2.getRoot(), 95, arr);
    cout << "Part3" << endl;
    tree2.vertSum(tree2.getRoot(), 0, m2);
    
    map<int, int> m3;
    BST<int> tree3;
    tree3.insert(20);
    tree3.insert(25);
    tree3.insert(23);
    tree3.insert(22);
    tree3.insert(45);
    tree3.insert(18);
    tree3.insert(17);
    tree3.insert(13);
    tree3.insert(12);
    tree3.insert(10);
    cout << "\nTestcase3" << endl;
    cout << "Part1" << endl;
    tree3.displayMinCover();
    cout << "Part2" << endl;
    tree3.findSumPath(tree3.getRoot(), 90, arr);
    cout << "Part3" << endl;
    tree3.vertSum(tree3.getRoot(), 0, m3);
    
    map<int, int> m4;
    BST<int> tree4;
    cout << "\nTestcase4" << endl;
    cout << "Part1" << endl;
    tree4.displayMinCover();
    cout << "Part2" << endl;
    tree4.findSumPath(tree4.getRoot(), 90, arr);
    cout << "Part3" << endl;
    tree4.vertSum(tree4.getRoot(), 0, m4);
    return 0;
}