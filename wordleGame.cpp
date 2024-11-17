// about to put what I have in my visual studio down here, here are some glitches I know about
/*
    Chooses the exact same word, which is lower
    For the grid all the blank spaces are gray and the grid isn't organized the best
*/
#include "Game.h"
#include "PerformanceReport.h"
#include <iostream>

using namespace std;
int main()
{
cout << "Hi";
cout << "Hello!";
  int choice;
  
  do {
      cout << "Wordle ..." << endl << endl;
      cout << "1. See the Rules" << endl;
      cout << "2. Play the Game" << endl;
      cout << "3. See Performance Report" << endl;
      cout << "4. Quit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
  
      Game wordle;
      switch (choice) {
          case 1:
              wordle.rules();
              break;
          case 2:
              cout << "\nWordle...\n\n";
              wordle.play();
              break;
          case 3:
              PerformanceReport::displayReport();
              break;
          case 4:
              cout << "Thank you for playing Wordle!" << endl;
              break;
          default:
              cout << "Invalid choice. Please try again." << endl;
      }
  } while (choice != 4);

  return 0;
}
