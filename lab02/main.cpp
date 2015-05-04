#include <iostream>
#include <forward_list>

using namespace std;

#include "lab2.h"

template<typename Type>
void print(forward_list<Type> list) {
    while(!list.empty()) {
        cout << list.front() << " ";
        list.pop_front();
    }
    cout << endl;
    return;
}

int main() {
    
    forward_list<char> numbers;
    
    for (int i = 26; i >= 0; --i) {
        numbers.push_front('a' + i);
    }
    cout << "List contents: "; print(numbers);
    // cout << "Number of prime numbers in forward_list: " << primeCount(numbers) << endl;
    
    // forward_list<int> numCopy;
    
    // for (int i = 1; i <= 10; ++i) {
    //     numCopy.push_front(i);
    // }
    
    // cout << "List contents of \"numbers\": "; print(numbers);
    // cout << "List contents of \"numCopy\": "; print(numCopy);
    
    // numCopy = listCopy(numbers, numCopy);
    
    // cout << "New list contents of \"numCopy\": "; print(numCopy);
    
    // List<int> list;
    
    // for (int i = 0; i < 10; ++i) {
    //     list.push_back(i + 1);
    // }
    
    // list.print();
    
    // list.elementSwap(list, 8);
    
    // list.print();
    
    forward_list<int> positions;
    positions.push_front(270);
    positions.push_front(6);
    positions.push_front(3);
    positions.push_front(2);
    positions.push_front(1);
    positions.push_front(0);
    
    cout << "Contents of 'numbers' at positions "; print(positions);
    printLots(numbers, positions);
    
    return 0;
}