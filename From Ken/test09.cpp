// Non-Fixed Size Array, or called VECTOR
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Array aryA is a Vector Array of Integers, which we don't know it has how many elements
  vector <int> aryA;

  // We add an element of Integer 10 to the Tail of the Array aryA
  aryA.push_back(10);
  // We add an element of Integer 31 to the Tail of the Array aryA
  aryA.push_back(31);
  // We add an element of Integer 22 to the Tail of the Array aryA
  aryA.push_back(22);
  // We add an element of Integer 44 to the Tail of the Array aryA
  aryA.push_back(44);

  // Print first value in aryA;
  cout << "The first element of the array aryA is: " << aryA[0] << "\n";

  // Print Length of aryA;
  cout << "The length of the array aryA is: " << aryA.size() << "\n";

  // Print all values in aryA
  for (int i=0;i<aryA.size();i++) {
    cout << "The " << i+1 << " element of the array aryA is: " << aryA[i] << "\n";
  }
}