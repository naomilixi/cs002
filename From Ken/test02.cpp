// Function
#include <iostream>

using namespace std;

int funFactorial(int intParm) {
  int intFactResult = 1;

  // Change intFactResult
  for (int i = 1; i <= intParm; i++) {
    intFactResult *= i;
  }

  return intFactResult;
}

int main() {
  int intN;

  cout << "Input a number: ";
  cin >> intN;

  cout << "The Factorial of the number is: " << funFactorial(intN) << "\n";
  cout << "The Factorial of the number times 2 is: " << funFactorial(intN*2) << "\n";
}
