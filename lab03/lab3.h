#ifndef LAB3_H
#define LAB3_H

#include <iostream>

using namespace std;

template<typename Type>
class TwoStackFixed {
    private:
        Type* stack1;
        Type* stack2;
        int max1;
        int max2;
        int space1;
        int space2;
        
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
        
        int size1();
        int size2();
    public:
        TwoStackFixed(int size, int maxtop);
        void pushStack1(Type value);
        void pushStack2(Type value);
        Type popStack1();
        Type popStack2();
        
        void printStacks();
};

template<typename Type>
class TwoStackOptimal {
    private:
        Type* stack1;
        Type* stack2;
        int space1;
        int space2;
        
        int maxSize;
        int remainingSpace;
        
        bool isFullStack1();
        bool isFullStack2();
        bool isEmptyStack1();
        bool isEmptyStack2();
    public:
        TwoStackOptimal(int size);
        void pushFlexStack1(Type value);
        void pushFlexStack2(Type value);
        Type popFlexStack1();
        Type popFlexStack2();
        
        void printStacks();
};

/*** Begin function definitions for class 'TwoStackFixed' ***/
template<typename Type>
TwoStackFixed<Type>::TwoStackFixed(int size, int maxtop) {
    
    if (maxtop > size) {
        cout << "Invalid values inputted. Exiting program..." << endl;
        exit(-1);
    }
    
    max1 = maxtop;
    max2 = size - maxtop;
    
    stack1 = new Type[size];
    stack2 = stack1 - max1;
    
    space1 = 0;
    space2 = 0;
}

template<typename Type>
bool TwoStackFixed<Type>::isFullStack1() {
    return (space1 >= max1) ? 1 : 0;
}

template<typename Type>
bool TwoStackFixed<Type>::isFullStack2() {
    return (space2 >= max2) ? 1 : 0;
}

template<typename Type>
bool TwoStackFixed<Type>::isEmptyStack1() {
    return (space1 == 0) ? 1 : 0;
}

template<typename Type>
bool TwoStackFixed<Type>::isEmptyStack2() {
    return (space2 == 0) ? 1 : 0;
}

template<typename Type>
void TwoStackFixed<Type>::pushStack1(Type value) {
    if (isFullStack1()) {
        cout << "Stack 1 is full, cannot push any further." << endl;
        return;
    }
    stack1[space1] = value;
    ++space1;
    return;
}

template<typename Type>
void TwoStackFixed<Type>::pushStack2(Type value) {
    if (isFullStack2()) {
        cout << "Stack 2 is full, cannot push any further." << endl;
        return;
    }
    int topOffset = max1 + max2 - space2 - 1;
    stack1[topOffset] = value;
    ++space2;
    return;
}

template<typename Type>
Type TwoStackFixed<Type>::popStack1() {
    if (isEmptyStack1()) {
        cout << "Stack 1 is empty, cannot pop any further." << endl;
        return 0;
    }
    Type valPopped = stack1[space1];
    --space1;
    return valPopped;
}

template<typename Type>
Type TwoStackFixed<Type>::popStack2() {
    if (isEmptyStack2()) {
        cout << "Stack 2 is empty, cannot pop any further." << endl;
        return 0;
    }
    Type valPopped = stack1[max1 + max2 - space2 - 1];
    --space2;
    return valPopped;
}

template<typename Type>
void TwoStackFixed<Type>::printStacks() {
    cout << "Stack 1 contents: ";
    for (int i = 0; i < space1; ++i) {
        cout << stack1[i] << ' ';
    }
    cout << endl;
    cout << "Stack 2 contents: ";
    for (int i = max1 + max2 - 1; i >= max1 + max2 - space2; --i) {
        cout << stack1[i] << ' ';
    }
    cout << endl;
    cout << "Entire array contains: ";
    for (int i = 0; i < max1 + max2; ++i) {
        cout << stack1[i] << ' ';
    }
    cout << endl;
    return;
}
/*** End function definitions for class 'TwoStackFixed' ***/

/*** Begin function definitions for class 'TwoStackOptimal' ***/
template<typename Type>
TwoStackOptimal<Type>::TwoStackOptimal(int size) {
    
    stack1 = new Type[size];
    maxSize = size;
    remainingSpace = size;
    space1 = 0;
    space2 = 0;
}

template<typename Type>
bool TwoStackOptimal<Type>::isFullStack1() {
    return (remainingSpace == 0) ? 1 : 0;
}

template<typename Type>
bool TwoStackOptimal<Type>::isFullStack2() {
    return (remainingSpace == 0) ? 1 : 0;
}

template<typename Type>
bool TwoStackOptimal<Type>::isEmptyStack1() {
    return (space1 == 0) ? 1 : 0;
}

template<typename Type>
bool TwoStackOptimal<Type>::isEmptyStack2() {
    return (space2 == 0) ? 1 : 0;
}

template<typename Type>
void TwoStackOptimal<Type>::pushFlexStack1(Type value) {
    if (isFullStack1()) {
        cout << "Stack 1 is full, cannot push any further." << endl;
        return;
    }
    stack1[space1] = value;
    ++space1;
    --remainingSpace;
    return;
}

template<typename Type>
void TwoStackOptimal<Type>::pushFlexStack2(Type value) {
    if (isFullStack2()) {
        cout << "Stack 2 is full, cannot push any further." << endl;
        return;
    }
    int topOffset = maxSize - 1 - space2;
    stack1[topOffset] = value;
    ++space2;
    --remainingSpace;
    return;
}

template<typename Type>
Type TwoStackOptimal<Type>::popFlexStack1() {
    if (isEmptyStack1()) {
        cout << "Stack 1 is empty, cannot pop any further." << endl;
        return 0;
    }
    Type valPopped = stack1[space1];
    --space1;
    ++remainingSpace;
    return valPopped;
}

template<typename Type>
Type TwoStackOptimal<Type>::popFlexStack2() {
    if (isEmptyStack2()) {
        cout << "Stack 2 is empty, cannot pop any further." << endl;
        return 0;
    }
    Type valPopped = stack1[maxSize - 1 - space2];
    --space2;
    ++remainingSpace;
    return valPopped;
}

template<typename Type>
void TwoStackOptimal<Type>::printStacks() {
    cout << "Stack 1 contents: ";
    for (int i = 0; i < space1; ++i) {
        cout << stack1[i] << ' ';
    }
    cout << endl;
    cout << "Stack 2 contents: ";
    for (int i = maxSize - 1; i >= maxSize - space2; --i) {
        cout << stack1[i] << ' ';
    }
    cout << endl;
    cout << "Entire array contains: ";
    for (int i = 0; i < maxSize - 1; ++i) {
        cout << stack1[i] << ' ';
    }
    cout << endl;
    return;
}
/*** End function definitions for class 'TwoStackOptimal' ***/

#endif