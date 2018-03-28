#include <iostream>
#include "BSTOperations.h"
using namespace std;

int main() {
    BSTOperations b;
    b.createBST();
    b.findMin();
    b.printKeyInRange();
    return 0;
}

