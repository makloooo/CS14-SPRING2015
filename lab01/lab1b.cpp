#include <iostream>
#include <list>

using namespace std;

template <typename Type>
void mergeSortList(list<Type>& list1, list<Type>& list2) {
    
    // Lists already sorted
    typename list<Type>::iterator it;
    
    for (it = list1.begin(); !list2.empty(); ++it) {
        if (it == list1.end()) {
            list1.push_back(list2.front());
            list2.pop_front();
        }
        if (list2.front() <= *it) {
            list1.splice(it, list2, list2.begin());
        } 
    }
    
    return;
}

int main() {
    
    list<char> list1;
    list<char> list2;
    list<char>::iterator it;
    
    for (int i = 48; i < 53; ++i) {
        list1.push_back(i);
        list2.push_back(i);
    }
    
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
    
    mergeSortList(list1, list2);

    cout << "List 1 contains: ";
    for (it = list1.begin(); it != list1.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    
    return 0;
}