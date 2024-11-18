/* De'Marion Brown and Tebryn Branch

   wordleGame.cpp

   November 17th, 2024

Task: Implement a text based Wordle game.

Parameters:
Must include a menu from which the user may choose to:

1. See the Rules.
-If the user chooses 1, the program will display the Wordle game rules in a nicely formatted way.


2. Play the Game.
-If the user chooses  2, the user begins the game, which prompts the computer to generate a random value equivalent to the position
of the word within the “fiveLetterWords.txt” file attached to this project assignment. The file contains 5757 lines of five-letter English words.
-After each try, the program will provide feedback to the player by redisplaying the list of words entered so far,
color-coding the letters as indicated on the Wordle rules:

Green – The letter is in the word and in the correct spot.
Yellow – The letter is in the word but in the wrong spot.
Gray – The letter is not in the word in any spot.


3. See Performance Report.
-At the end of the game, the program will append the player’s score to the file “wordleStats.txt”.
-If the user chooses 3, the program will process the records stored in the "wordleStats.txt" file
and display a summary indicating the number of games played; the percentage of games guessed; and the average number of tries needed to guess a word.


4. Quit.

When does the player win?
The game ends when either:

The player wins - Guesses the word.
-System displays a congratulatory message.
-The player’s score is equal to the number of tries it took to guess the word (1-6).

The player loses - Could not guess the word on six tries.
-Program reveals the word.
-The player’s score is equal to 0.

Functionality, Implementation, and Program Requirements:
-The implementation must rely on an Object-Oriented approach. Class(es) must use separate specification (.h) and implementation (.cpp) files.
-The Wordle grid must be implemented as a dynamically allocated, two-dimensional array data member, of 6 by 5 characters.
-The current try must be stored in a static data member. Appropriate setter and getter member functions must be defined.
-The program should validate the information entered by the user and display appropriate error messages. Exception handling must be added when appropriate.


*/

// Header files
#include "Game.h"
#include "PerformanceReport.h"
#include <iostream>

// namespace
using namespace std;

// main function
int main()
{
    //cout << "Hi";
    //cout << "Hello!";

    // choice variable for user input
    int choice;

    // main do while loop
    do {
        // print out menu
        cout << "Wordle ..." << endl << endl;
        cout << "1. See the Rules" << endl;
        cout << "2. Play the Game" << endl;
        cout << "3. See Performance Report" << endl;
        cout << "4. Quit" << endl;

        // prompt user for choice
        cout << "Enter your choice: ";
        cin >> choice;

        // define wordle Game
        Game wordle;

        // switch statement for options
        switch (choice) {
        case 1:
            // print out rules
            wordle.rules();
            break;
        case 2:
            // start the game with "Wordle..."
            cout << "Wordle...\n\n";
            // play the game
            wordle.play();
            break;
        case 3:
            // Display the Performance Report overall
            PerformanceReport::displayReport();
            break;
        case 4:
            // thank you message and exit
            cout << "Thank you for playing Wordle!" << endl;
            break;
        default:
            // if any other option is chosen print out a message asking user to try again
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); // control statement

    // return a 0 to the operating system
    return 0;
}
