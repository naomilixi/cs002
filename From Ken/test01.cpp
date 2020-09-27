// getline (How to input a string with spaces between words)
#include <iostream>

using namespace std;

// int main() {
//   string strInputA;
//   int intA, intB;

//   cout << "What is strInputA: ";
//   getline(cin, strInputA);

//   cout << "You type: " << strInputA << "\n";
// }

int main() {
  string strInputA;
  int intA, intB;

  cout << "What is intA: ";
  cin >> intA;
  cin.ignore();

  cout << "What is strInputA: ";
  getline(cin, strInputA);

  cout << "You type: " << intA << "\n";
  cout << "You type: " << strInputA << "\n";
}