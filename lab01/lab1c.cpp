#include <iostream>
#include <list>

using namespace std;

int main() {
    
    int rotateNum = 0;
    list<int> origList;
    
    for (int i = 0; i < 6; ++i) {
        origList.push_back(2*i);
    }
    
    list<int>::iterator it;
    it = origList.begin();
    
    cout << "OrigList contains: ";
    for (it = origList.begin(); it != origList.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    
    cout << "Enter node to rotate: ";
    cin >> rotateNum; cout << endl;
    
    for (int i = 0; i < rotateNum; ++i) {
        if (it == origList.end()) {
            it = origList.begin();
        }
        ++it;
    }
    
    for (int i = 0; i < rotateNum; ++i) {
        if (it == origList.end()) {
            it = origList.begin();
        }
        origList.push_front(origList.back());
        origList.pop_back();
    }
    
    it = origList.begin();
    
    cout << "OrigList contains: ";
    for (it = origList.begin(); it != origList.end(); ++it) {
        cout << ' ' << *it;
    }
    cout << endl;
    
    return 0;
}