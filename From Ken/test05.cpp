// test04 Not using OO

#include <iostream>

using namespace std;

// Declare a Class (类)
class ClsBox {
  public:
    // Properties of the Class
    int intWidth;
    int intDepth;
    int intHeight;

    // Contructor of the Class
    // Means: when this class is initiated, what should be done ONCE
    ClsBox() {
      // Initialize all box to 1 x 1 x 1
      intWidth = 1;
      intDepth = 1;
      intHeight = 1;
    }
};

int main() {
  int intWidth = 1;
  int intDepth = 1;
  int intHeight = 1;

  // New Object
  cout << "The Initial Volume of the Box is: ";
  cout << intHeight * intWidth * intDepth << "\n";

  cout << "Enter Height of the Box: ";
  cin >> intHeight;
  cout << "Enter Width of the Box: ";
  cin >> intWidth;
  cout << "Enter Depth of the Box: ";
  cin >> intDepth;
  cout << "The Volume of the Box is: ";
  cout << intHeight * intWidth * intDepth << "\n";
}
