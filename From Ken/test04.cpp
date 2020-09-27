// Introduction to Object Oriented Programming

#include <iostream>

using namespace std;

// Declare a Class (类)
class ClsBox {
  private:
    int intHeight = 10;


  public:
    // Properties of the Class
    int intWidth;
    int intDepth;



    // Contructor of the Class
    // Means: when this class is initiated, what should be done ONCE
    ClsBox() {
      // Initialize all box to 1 x 1 x 1
      intWidth = 1;
      intDepth = 1;
      // intHeight = 1;
    }



    // Methods of the Class
    int funGetVolume() {
      return intWidth * intDepth * intHeight;
    }


    // Set Height of Box
    void funSetHeight(int intInputHeight) {
      intHeight = intInputHeight;
    }
};

int main() {
  // New Object
  ClsBox objBox01 = ClsBox();
  cout << "The Initial Volume of the Box 01 is: ";
  cout << objBox01.funGetVolume() << "\n";

  int intTempHeight;
  cout << "Enter Height of the Box: ";
  cin >> intTempHeight;
  objBox01.funSetHeight(intTempHeight);


  cout << "Enter Width of the Box: ";
  cin >> objBox01.intWidth;
  cout << "Enter Depth of the Box: ";
  cin >> objBox01.intDepth;
  cout << "The Volume of the Box is: ";
  cout << objBox01.funGetVolume() << "\n";
}
