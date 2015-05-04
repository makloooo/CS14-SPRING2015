#include <iostream>
#include <forward_list>

using namespace std;

#include "lab2.h"

bool isPrime(int n) {
    //Returns true/false depending on if the number is prime or not
    if (n < 2) return false;
    for (int i = n - 1; i > 1; --i) {
        if (n % i == 0) return false;
    }
    return true;
}

int primeCount(forward_list<int> lst) {
    //Recursive calls to count prime numbers
    
    if (lst.empty()) {
        return 0;
    }
    if (isPrime(lst.front())) {
        lst.pop_front();
        return primeCount(lst) + 1;
    }
    else {
        lst.pop_front();
        return primeCount(lst);
    }
}