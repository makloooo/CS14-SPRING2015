#include <iostream>
#include <list>

using namespace std;

template <typename Type>
void mergeList(list<Type>& list1, list<Type>& list2) {
    
    typename list<Type>::iterator it;
    
    for (it = list2.begin(); !list1.empty(); ++it) {
        list2.splice(it, list1, list1.begin());
        if (it == list2.end()) {
            list2.push_back(list1.front());
            list1.pop_front();
        }
    }
    
    return;
}

int main() {
    
    list<char> list1;
    list<char> list2;
    list<char>::iterator it;
    
    list1.push_back('c');
    list1.push_back('a');
    list1.push_back('a');
    list1.push_back('b');
    list2.push_back('b');
    list2.push_back('f');
    list2.push_back('e');
    list2.push_back('r');
    list2.push_back('n');
    list2.push_back('p');
    
    cout << "List 1 contains: ";
    for (it = list1.begin(); it != list1.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    cout << "List 2 contains: ";
    for (it = list2.begin(); it != list2.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    
    mergeList(list1, list2);
    
    cout << "Final List contains: ";
    for (it = list2.begin(); it != list2.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    
    return 0;
}