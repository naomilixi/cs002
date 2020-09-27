// About setw and left in <iomanip>

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int intA = 1234;
  cout << "intA:|" << intA << "|\n";
  cout << "intA:|" << setw(3) << intA <<  "|\n";
}