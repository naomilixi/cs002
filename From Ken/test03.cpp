// Recursive Function
#include <iostream>

using namespace std;

int funFactorial(int intParm) {
  // Recursive Function
  if (intParm == 1) {
    return 1;
  } else {
    return intParm * funFactorial(intParm - 1);
  }
}

int main() {
  int intN;

  cout << "Input a number: ";
  cin >> intN;

  cout << "The Factorial of the number is: " << funFactorial(intN) << "\n";
  cout << "The Factorial of the number times 2 is: " << funFactorial(intN*2) << "\n";
}
