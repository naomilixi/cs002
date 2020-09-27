// Name: Li Xi Naomi
// Student ID: 1155156672
// Email: 1155156672@link.cuhk.edu.hk

// *** Set bolPlayByComputer = true if you want to play by Computer instead of play by yourself ***
bool bolPlayByComputer = true;
// SET bolPlayByComputer = true and RUN this program, you need to enter M, C, B,

// then the program will GENERATE EACH MOVE and it's state AUTOMATICALLY.

// Pls. note that [Play By Computer] DOES NOT GUARANTINE THE FASTEST SOLUTION!
// I'm just using Recursive Function to find A SOLUTION, not finding ALL SOLUTIONS.



// Include Libraries
#include <iostream>
#include <iomanip>
// This vector for bolPlayByComputer = true only
// I try to use vector to REMEMBER ALL Previous States and Moves, in order to use
// Recursive Function to find a solution.
#include <vector>



// use namespace std
using namespace std;



// Class Definition
class ClsMC {
  // Public Properties and Methods
  public:
    // Class Constructor
    ClsMC() {
      // Nothing to do here
    };



    // Variables
    int intMTotal = 0;  // = M = Total No. of Missionaries
    int intCTotal = 0;  // = C = Total No. of Cannibals
    int intBMax = 0; // = B = Boat Capacity

    int intM = 0; // = m = No. of Missionaries on the Left Bank, so (intMTotal - intM) = No. of Missionaries on the Right Bank
    int intC = 0; // = c = No. of Cannibals on the Left Bank, so (intCTotal - intC) = No. of Cannibals on the Right Bank
    int intB = 0; // = b = 0 means boat on right, 1 means boat on left.

    int intDigitM = 0; // No. of digits of m
    int intDigitC = 0; // No. of digits of c
    int intDigitS = 0; // No. of digits of State

    int intCounter = 0; // State Counter



    // Methods

    // Method to check Win
    bool funIsWin() {
      if (intM == 0 && intC == 0 && intB == 0) {
        return true;
      } else {
        return false;
      }
    }



    // Method to check Game Over
    bool funIsGameOver() {
      if (intM != 0 && intM < intC ||
         (intMTotal - intM) != 0 && (intMTotal - intM) < (intCTotal - intC)) {
        return true;
      } else {
        return false;
      }
    }



    // Method to check valid input of M, C, B, 
    // and Set values if valid
    bool funCheckAndSetValidMCB(int intP_MTotal, int intP_CTotal, int intP_BMax) {
      bool bolValid = false;

      if (intP_MTotal < intP_CTotal) {
        // M must be >= C
      } else if (intP_MTotal < 1 || intP_CTotal < 1) {
        // M & C must be >= 1
      } else if (intP_BMax < 2) {
        // B must be >= 2
      } else if (intP_BMax == 2 && (intP_MTotal > 3 || intP_CTotal > 3)) {
        // When B = 2, M and C must be <= 3
      } else if (intP_BMax == 3 && (intP_MTotal > 5 || intP_CTotal > 5)) {
        // When B = 3, M and C must be <= 5
      } else {
        bolValid = true;
      }

      if (!bolValid) {
        // Output Error
        cout << "Invalid input!\n";
      } else {
        // OK, Set Values for M, C, B
        intMTotal = intP_MTotal;
        intCTotal = intP_CTotal;
        intBMax = intP_BMax;

        // Set Values for m, c, b
        intM = intP_MTotal;
        intC = intP_CTotal;
        intB = 1;

        // Set digits
        intDigitM = to_string(intM).length();
        intDigitC = to_string(intC).length();
        intDigitS = max(intDigitM, intDigitC) + 1;

        // Set Counter
        intCounter = 1;
      }

      return bolValid;
    }



    // Display Current State
    void funDisplayState() {
      cout << "State " << setw(intDigitS) << intCounter << ": [" 
           << setw(intDigitM) << intM << "m, "
           << setw(intDigitC) << intC << "c]"
           << ((intB == 1) ? "v ~~~  [" : "  ~~~ v[")
           << setw(intDigitM) << (intMTotal - intM) << "m, "
           << setw(intDigitC) << (intCTotal - intC) << "c]\n";
    }
    // Overload Display State for Display Result for Computer Play
    void funDisplayState(int intCounter_Com, int intM_Com, int intC_Com, int intB_Com) {
      cout << "State " << setw(intDigitS) << intCounter_Com << ": [" 
           << setw(intDigitM) << intM_Com << "m, "
           << setw(intDigitC) << intC_Com << "c]"
           << ((intB_Com == 1) ? "v ~~~  [" : "  ~~~ v[")
           << setw(intDigitM) << (intMTotal - intM_Com) << "m, "
           << setw(intDigitC) << (intCTotal - intC_Com) << "c]\n";
    }


    // Check End Of Game
    bool funCheckGameEnd() {
      bool bolGameEnd;
      if (funIsWin()) {
        // Show Win
        cout << "Congratulations! You win!\n";
        bolGameEnd = true;
      } else if (funIsGameOver()) {
        // Show Gave Over
        cout << "Game over! Missionaries eaten!\n";
        bolGameEnd = true;
      } else {
        // Continue to Play
        bolGameEnd = false;
      }
      return bolGameEnd;
    }



    // Check Next Move Valid for Mb and Cb
    bool funCheckNextMoveValid(int intMb, int intCb) {
      bool bolValid = false;
      if ((intMb + intCb) < 1) {
        // At least one people in boat
        bolValid = false;
      } else if ((intMb + intCb) > intBMax) {
        // Should not large than Boat Maximum Capacity
        bolValid = false;
      } else if (intCb > intMb && intMb != 0) {
        // Missionaries will be eaten aboard
        bolValid = false;
      } else {
        if (intB == 1) {
          if (intMb > intM || intCb > intC) {
            // Not Enough intM or intC on Left Bank
            bolValid = false;
          } else {
            bolValid = true;
          }
        } else {
          if (intMb > (intMTotal - intM) || intCb > (intCTotal - intC)) {
            // Not Enough (intMTotal - intM) or (intCTotal - intC) on Right Bank
            bolValid = false;
          } else {
            bolValid = true;
          }
        }
      }
      return bolValid;
    }



    // Move to Next Step
    void funMoveNextStep(int intMb, int intCb) {
      // Increment Counter
      intCounter += 1;

      // Change intM and intB
      if (intB == 1) {
        // On Left Before Move
        intM = intM - intMb;
        intC = intC - intCb;
      } else {
        // On Right Before Move
        intM = intM + intMb;
        intC = intC + intCb;
      }

      // Change intB
      if (intB == 0) {
        intB = 1;
      } else {
        intB = 0;
      }
    }



    // The following for Computer Play (i.e. bolPlayByComputer = true)
    string funGetCurrentStateInString() {
      return to_string(intM) + " " + to_string(intC) + " " + to_string(intB);
    }

    void funSetNextMC(int intP_MTotal, int intP_CTotal, int intP_BMax, 
                      int intP_M, int intP_C, int intP_B, int intP_Counter,
                      int intP_DigitM, int intP_DigitC, int intP_DigitS) {
      intMTotal = intP_MTotal;
      intCTotal = intP_CTotal;
      intBMax = intP_BMax;
      intM = intP_M;
      intC = intP_C;
      intB = intP_B;
      intCounter = intP_Counter;
      intDigitM = intP_DigitM;
      intDigitC = intP_DigitC;
      intDigitS = intP_DigitS;
    }
};



// Function(s) play by Computer
vector <string> aryWinStates;
vector <string> aryWinMoves;
bool funGetSolution(vector <string> aryPreviousStates, vector <string> aryPreviousMoves, ClsMC objMC) {
  // Check Win
  bool bolWin = objMC.funIsWin();
  if (bolWin) {
    // Append Last Win State to States Array
    aryPreviousStates.push_back(objMC.funGetCurrentStateInString());

    // Save Win States
    aryWinStates = aryPreviousStates;

    // Save Win Moves
    aryWinMoves = aryPreviousMoves;
    return true;
  }

  // Check Loss
  bool bolLoss = objMC.funIsGameOver();
  if (bolLoss) {
    return false;
  }

  // Check Same as Previous State?
  for (int i=0;i<aryPreviousStates.size();i++) {
    if (aryPreviousStates[i] == objMC.funGetCurrentStateInString()) {
      return false;
    }
  }

  // No Win or Fail, or Not the same before?  Continue!!!

  // Generate Available Moves
  vector <int> aryMb;
  vector <int> aryCb;
  vector <int> aryValid;
  for (int intMb=0; intMb<=objMC.intBMax; intMb++) {
    for (int intCb=0; intCb<=objMC.intBMax; intCb++) {
      aryMb.push_back(intMb);
      aryCb.push_back(intCb);

      // Check intMb, intCb valid?
      bool bolMoveValid = objMC.funCheckNextMoveValid(intMb, intCb);
      if (bolMoveValid) {
        aryValid.push_back(true);
      } else {
        aryValid.push_back(false);
      }
    }
  }

  // Set aryPreviousState
  aryPreviousStates.push_back(objMC.funGetCurrentStateInString());

  // For Each Valid Input
  bool bolReturn = false;
  for (int i=0;i<aryMb.size();i++) {
    if (aryValid[i]) {
      // New objMC
      ClsMC objMCNew = ClsMC();

      // New m, c, b, intCounter
      int intCounter_New = objMC.intCounter + 1;
      int intM_New = 0;
      int intC_New = 0;
      int intB_New = 0;
      if (objMC.intB == 1) {
        // Original on Left
        intM_New = objMC.intM - aryMb[i];
        intC_New = objMC.intC - aryCb[i];
        intB_New = 0;
      } else {
        // Original on Right
        intM_New = objMC.intM + aryMb[i];
        intC_New = objMC.intC + aryCb[i];
        intB_New = 1;
      }
      objMCNew.funSetNextMC(objMC.intMTotal, objMC.intCTotal, objMC.intBMax, 
                            intM_New, intC_New, intB_New, intCounter_New, 
                            objMC.intDigitM, objMC.intDigitC, objMC.intDigitS);

      // Update aryPreviousMoves
      vector <string> aryMoves = aryPreviousMoves;
      string strMove = to_string(aryMb[i]) + " " + to_string(aryCb[i]);
      aryMoves.push_back(strMove);

      // This is true?
      bool bolNewMC = false;
      bolNewMC = funGetSolution(aryPreviousStates, aryMoves, objMCNew);

      if (bolNewMC) {
        bolReturn = true;
        break;
      }
    }
  }
  return bolReturn;
}



// Main Program
int main () {
  // Init Class
  ClsMC objMC = ClsMC();



  // 1. Ask for Input Total Missionaries, Total Cannibals and Boat Capacity

  // Set bolInputEnd = true when Input
  bool bolInputEnd = false;

  // Get Inputs for M, C, B until all inputs are valid
  while (!bolInputEnd) {
    // Get Inputs
    int intT_MTotal, intT_CTotal, intT_BMax;
    cout << "Enter boat capacity: ";
    cin >> intT_BMax;
    cout << "Enter #missionaries: ";
    cin >> intT_MTotal;
    cout << "Enter #cannibals: ";
    cin >> intT_CTotal;
    cin.ignore(); // This line make sure getline will not read last \n !!!

    // Validate Inputs
    bolInputEnd = objMC.funCheckAndSetValidMCB(intT_MTotal, intT_CTotal, intT_BMax);
  };



  // From Here, Start Playing!


  // Game Ended?
  bool bolGameEnded = false;

  // Input Next Move Ended?
  bool bolInputNextMoveEnd = false;



  // Play by Human or Play by Computer?

  if (!bolPlayByComputer) {

    // Play by Human (See "else" section for Play by Computer)
    while (!bolGameEnded) {
      // Display Current State
      objMC.funDisplayState();

      // Check End of Game
      bolGameEnded = objMC.funCheckGameEnd();

      if (!bolGameEnded) {
        // Input Next Move
        bolInputNextMoveEnd = false;

        while (!bolInputNextMoveEnd) {
          // Get Input for aboard

          // Init vars.
          int intMb = 0; // Mb on board
          int intCb = 0; // Cb on board
          string strInput; // Input String

          // Get Input String
           
          cout << "Enter #m #c aboard boat: ";
          getline(cin, strInput);
          
          // Split Input String into 2 Integer
          intMb = stoi(strInput.substr(0, strInput.find_first_of(" ")));
          intCb = stoi(strInput.substr(strInput.find_first_of(" ")+1));

          // Check Validity of Mb And Cb
          bolInputNextMoveEnd = objMC.funCheckNextMoveValid(intMb, intCb);

          if (bolInputNextMoveEnd) {
            // If Next Move Valid, Move Next Step
            objMC.funMoveNextStep(intMb, intCb);
          } else {
            // Display Invalid Input
            cout << "Invalid input!\n";
          }
        }
      }
    }
  } else {
    // Play by Computer (Recursive Function)


    // Declare boolean bolHaveSolution
    bool bolHaveSolution = false;

    // Declare Previous States
    vector <string> aryPreviousStates;

    // Declare Previous Moves
    vector <string> aryPreviousMoves;

    // Calculate Solution by Recursive Function
    bolHaveSolution = funGetSolution(aryPreviousStates, aryPreviousMoves, objMC);

    if (bolHaveSolution) {
      // Solution is found

      // cout << "The following solution is calculated by Recursive Function: \n";
      for (int i=0;i<aryWinStates.size();i++) {
        int intCounter_Com, intM_Com, intC_Com, intB_Com;
        intCounter_Com = i + 1;
        intM_Com = stoi(aryWinStates[i].substr(0, aryWinStates[i].find_first_of(" ")));
        intC_Com = stoi(aryWinStates[i].substr(aryWinStates[i].find_first_of(" ")+1, aryWinStates[i].find_last_of(" ")-aryWinStates[i].find_first_of(" ")-1));
        intB_Com = stoi(aryWinStates[i].substr(aryWinStates[i].find_last_of(" ")+1, 1));
        objMC.funDisplayState(intCounter_Com, intM_Com, intC_Com, intB_Com);
        if (i < aryWinMoves.size()) {
          cout << "Enter #m #c aboard boat: " << aryWinMoves[i] << "\n";
        } else {
          cout << "Congratulations! You win!\n";
        }
      }
    } else {
      // No Solution
      cout << "No Solution\n";
    }
  }
}
// Program End