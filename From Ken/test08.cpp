// Array (Fixed Size)
#include <iostream>

using namespace std;

int main() {
  // Array aryA is an Array of Integers, which has 3 elements 10, 30, and 21 respectively
  int aryA[3] = {10,30,21};

  // Print first value in aryA;
  cout << "The first element of the array aryA is: " << aryA[0] << "\n";

  // Print all values in aryA
  for (int i=0;i<sizeof(aryA)/sizeof(aryA[0]);i++) {
    cout << "The " << i+1 << " element of the array aryA is: " << aryA[i] << "\n";
  }
}