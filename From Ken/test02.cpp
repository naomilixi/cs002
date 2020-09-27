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
  int intResult;

  cout << "Input a number: ";
  cin >> intN;

  intResult = funFactorial(intN);

  cout << "The Factorial of the number is: " << intResult << "\n";
}