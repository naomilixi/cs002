// 三元表达式
#include <iostream>

using namespace std;

int main() {
  bool bolA = true;
  int intA = 123;

  // Not using THREE
  if (bolA) {
    cout << "Not Using 3.  It is true\n";
  } else {
    cout << "Not Using 3.  It is false\n";
  }

  // Using THREE
  cout << (bolA ? "Using 3. It is true\n" : "Using 3. It is false\n");

  cout << ((intA == 234) ? "intA Using 3. It is true\n" : "intA Using 3. It is false\n");
}