// Header files
#include "Game.h"
#include "Grid.h"
#include "PerformanceReport.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <stdio.h>  // Add these headers
#include <stdlib.h> // 
#include <time.h>  //
#include <new>
#include <cctype>

// namespace
using namespace std;
// Constructor
Game::Game() : tries(0) {

	// initalize totalWords and line to 0 and null
	int totalWords = 0;
	string line;

	// try
	try
	{
		// make file variable
		ifstream file("fiveLetterWords.txt");
		
		// if the file can't load
		if (!file)
		{
			string wrongFile = "File not found.";
			throw wrongFile;
		}
		//file.open("fiveLetterWords.txt", ios::in);

		// get each line from the file
		while (getline(file, line)) {
			totalWords++;
		}

		
		file.clear();
		file.seekg(0);


		srand(time(NULL)); // Seed to produce a random number

		// integer for ranodm index for word chosen
		int randomIndex = rand() % totalWords;

		for (int i = 0; i < randomIndex; i++) {
			getline(file, line);
		}
		word = line;


	} // if the wrong file is chosen
	catch (string wrongFile)
	{
		fileError();
		cout << "Please attach fiveLetterWords.txt to the repository.\n";
	}
}

string Game::getWord() {
	return word;
}

// prints out rules
void Game::rules() {
	cout << "\nIn wordle you need to guess the 5-letter word in 6 or less tries" << endl;
	cout << "Green means the letter is in the correct position" << endl;
	cout << "Yellow means the letter is in the word but in the wrong position" << endl;
	cout << "Gray means the letter is not in the word" << endl;
	cout << "Red means you put a duplicate of a letter that is in the word" << endl << endl;
}


void Game::play() {
	// initalize the guesses for the grid
	vector<string> guesses(6, "     ");

	// while the tries are less than 6
	while (tries < 6) {
		
		// print out the round 
		cout << "Round " << tries + 1 << endl;
		
		// prompt user for a guess
		string guess;
		cout << "Enter word (5-letters): ";
		cin >> guess;

		// make sure the input is formatted properly by making it lowercase
		for (char& l : guess) {
			l = tolower(l);
		}

		// if the user inputs a word that isn't 5 letters
		if (Grid::stringLength(guess) != 5) {
			cout << "Invalid input. Please enter a 5-letter word." << endl;
			//cout << "Enter word (5-letters): ";
			//cin >> guess;
			continue;
		}

		// put the guess on the grid
		guesses[tries] = guess;

		// increment tries
		tries++;

		// line before the grid gets printed out
		cout << "---------------------" << endl;

		// print out grid using for loop and the displayFeedback function
		for (int i = 0; i < 6; i++) {
			Grid::displayFeedback(word, guesses[i]);
		}

		// if the guess is equal to the word print out a congratulatory message
		if (guess == word) {
			cout << "Congratulations! You guessed the word in " << tries << " tries." << endl;
			PerformanceReport::saveScore(tries);
			return;
		}
	}

	// if the user doesn't guess the word in 6 tries then print this out and save the score as 0
	cout << "Sorry, you didn't guess the word. The correct word was: " << word << endl;
	PerformanceReport::saveScore(0);
}

// if the worng file is opened print this out
void Game::fileError()
{
	cout << "ERROR: Wrong file was opened\n";
}
