
#include <iostream>
#include <stack>
using namespace std;
#include "lab3.h"

void tsfTest() {
    cout << "Begin 'TwoStackFixed' class testing..." << endl;
    TwoStackFixed<int> dblStack(10, 6);
    for (int i = 0; i < 7; ++i) dblStack.pushStack1(i);
    for (int i = 0; i < 5; ++i) dblStack.pushStack2(i);
    dblStack.printStacks();
    dblStack.popStack1();
    dblStack.popStack2();
    dblStack.printStacks();
    for (int i = 0; i < 6; ++i) dblStack.popStack1();
    for (int i = 0; i < 4; ++i) dblStack.popStack2();
    dblStack.printStacks();
    return;
}

void tsoTest() {
    cout << "Begin 'TwoStackOptimal' class testing..." << endl;
    TwoStackOptimal<int> flxStack(10);
    for (int i = 0; i < 7; ++i) flxStack.pushFlexStack1(i);
    for (int i = 0; i < 5; ++i) flxStack.pushFlexStack2(i);
    flxStack.printStacks();
    flxStack.popFlexStack1();
    flxStack.popFlexStack2();
    flxStack.printStacks();
    for (int i = 0; i < 6; ++i) flxStack.popFlexStack1();
    for (int i = 0; i < 4; ++i) flxStack.popFlexStack2();
    flxStack.printStacks();
    for (int i = 0; i < 10; ++i) flxStack.pushFlexStack2(2*i);
    flxStack.printStacks();
    return;
}

template<typename Type>
void printStack(stack<Type> A) {
    while(!A.empty()) {
        cout << A.top() << ' ';
        A.pop();
    }
    cout << endl;
    return;
}

template<typename Type>
void showTowerStates(int n, stack<Type>& A, stack<Type>& B, stack<Type>& C) {
    static stack<Type>* origA = &A;
    static stack<Type>* origB = &B;
    static stack<Type>* origC = &C;
    // Base case
    if (n == 1) {
        C.push(A.top());
        A.pop();
        cout << "Moved " << n << " from peg ";
        if (&A == origA) cout << "A";
        else if (&A == origB) cout << "B";
        else if (&A == origC) cout << "C";
        cout << " to ";
        if (&C == origA) cout << "A";
        else if (&C == origB) cout << "B";
        else if (&C == origC) cout << "C";
        cout << endl;
        return;
    }
    
    else {
        showTowerStates(n - 1, A, C, B);
        C.push(A.top());
        A.pop();
        cout << "Moved " << n << " from peg ";
        if (&A == origA) cout << "A";
        else if (&A == origB) cout << "B";
        else if (&A == origC) cout << "C";
        cout << " to ";
        if (&C == origA) cout << "A";
        else if (&C == origB) cout << "B";
        else if (&C == origC) cout << "C";
        cout << endl;
        showTowerStates(n - 1, B, A, C);
    }
    return;
}

template<typename Type>
void hanoiPuzzle() {
    stack<Type> A;
    stack<Type> B;
    stack<Type> C;
    
    cout << "How many disks are going to be used in the puzzle?" << endl;
    int disks = 0;
    cin >> disks;
    for (int i = disks; i > 0; --i) A.push(i);
    cout << "Stack A: "; printStack(A);
    cout << "Stack B: "; printStack(B);
    cout << "Stack C: "; printStack(C);
    showTowerStates<Type>(disks, A, B, C);
    cout << "Stack A: "; printStack(A);
    cout << "Stack B: "; printStack(B);
    cout << "Stack C: "; printStack(C);
    return;
}

int main() {
    // tsfTest();
    // cout << "----------------------------------------" << endl;
    // tsoTest();
    // cout << "----------------------------------------" << endl;
    hanoiPuzzle<int>();
    return 0;
}