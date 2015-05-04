#ifndef LAB2_H
#define LAB2_H

#include <iostream>
#include <forward_list>

using namespace std;

template<typename TypeClass>
struct Node {
    TypeClass data;
    Node* next;
    Node(TypeClass data) : data(data), next(0) {};
};

template<typename TypeClass>
class List {
    private:
        Node<TypeClass>* head;
        Node<TypeClass>* tail;
    public:
        List<TypeClass>();
        List<TypeClass> elementSwap(List<TypeClass>& lst, int pos);
        int size();
        void push_back(TypeClass value);
        void print();
};

template<typename TypeClass>
List<TypeClass>::List() {
    head = 0;
    tail = 0;
}

template<typename TypeClass>
int List<TypeClass>::size() {
    int count = 0;
    for (Node<TypeClass>* currObj = head; currObj != 0; currObj = currObj->next) {
        ++count;
    }
    return count;
}

template<typename TypeClass>
void List<TypeClass>::push_back(TypeClass value) {
    
    Node<TypeClass>* newObj = new Node<TypeClass>(value);
    
    if (head == 0) {
        head = newObj;
        head->data = value;
        head->next = head;
        tail = head;
        tail->next = 0;
    }
    else if (head == tail) {
        head->next = newObj;
        tail = newObj;
    }
    else {
        tail->next = newObj;
        tail = newObj;
    }
}

template<typename TypeClass>
void List<TypeClass>::print() {
    Node<TypeClass>* currObj = 0;
    for (currObj = head; currObj != 0; currObj = currObj->next) {
        cout << currObj->data << ' ';
    }
    cout << endl;
}

template<typename TypeClass>
List<TypeClass> List<TypeClass>::elementSwap(List<TypeClass>& lst, int pos) {
    //Swaps node pointers (not values) at pos & pos+1
    
    Node<TypeClass>* currObj = head;
    if (pos == 0) {
        Node<TypeClass>* tempNode = currObj->next->next;
        head = currObj->next;
        head->next = currObj;
        currObj->next = tempNode;
        return *this;
    }
    for (int i = 0; i < pos - 1; ++i) {
        currObj = currObj->next;
    }
    
    if (pos == size() - 1 || currObj == 0) {
        return *this;
    }
    
    else {
        Node<TypeClass>* tempNode = currObj->next;
        Node<TypeClass>* tempNext = tempNode->next;
        Node<TypeClass>* tempDblNext = tempNext->next;
        currObj->next = tempNext;
        tempNext->next = tempNode;
        tempNode->next = tempDblNext;
    }
    
    return *this;
}

bool isPrint(int n);
int primeCount(forward_list<int> lst);

template<typename Type> 
forward_list<Type> listCopy(forward_list<Type> L, forward_list<Type> P) {
    // Copy L to P in reverse order only going through it once
    // Templates cannot be separated into two files.
    
    P.clear();
    
    while (!L.empty()) {
        P.push_front(L.front());
        L.pop_front();
    }
    
    return P;
}

template<typename Type>
void printLots (forward_list<Type> L, forward_list<int> P) {
    int count = 0;
    while(!L.empty() && !P.empty()) {
        if (P.front() == count) {
            cout << L.front() << " ";
            P.pop_front();
        }
        L.pop_front();
        ++count;
    }
    if(!P.empty()) {
        cout << "\nforward_list 'P' contained some positions which were invalid." << endl;
    }
    return;
}

#endif