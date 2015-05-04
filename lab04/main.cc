//--------------------------------------------------
//Name: Mark Lieu
//SID: 861148602
//Date: 04/11/2015
//--------------------------------------------------

#include <iostream>
#include <sstream>

using namespace std;

#include "lab4.h"

int main(int argc, char *argv[]) {
    
    istringstream intArg(argv[1]);
    int k;
    if (!(intArg >> k)) {
        cout << "Invalid number, enter an integer." << endl;
        exit(-1);
    }
    
    cout << "Preorder: " << endl;
    PrePrimes(k);
    cout << "Postorder: " << endl;
    PostPrimes(k);
    cout << "Sorted: " << endl;
    SortedPrimes(k);
    return 0;
}