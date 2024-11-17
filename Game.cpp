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

using namespace std;
// Try this
Game::Game() : tries(0) {

	// added these definitions back in
	int totalWords = 0;
	string line;

	try
	{
		ifstream file("fiveLetterWords.txt");
		if (!file)
		{
			string wrongFile = "File not found.";
			throw wrongFile;
		}
		//file.open("fiveLetterWords.txt", ios::in);

		while (getline(file, line)) {
			totalWords++;
		}


		file.clear();
		file.seekg(0);


		srand(time(NULL)); // Seed to produce a random number

		int randomIndex = rand() % totalWords;

		for (int i = 0; i < randomIndex; i++) {
			getline(file, line);
		}
		word = line;


	}	// for some reason putting string works, for now, we were still running into an error with wrong file for whatever reason
	catch (string wrongFile)
	{
		fileError();
		cout << "Please attach fiveLetterWords.txt to the repository.\n";
	}
}
string Game::getWord() {
	return word;
}

void Game::rules() {
	cout << "\nIn wordle you need to guess the 5-letter word in 6 or less tries" << endl;
	cout << "Green means the letter is in the correct position" << endl;
	cout << "Yellow means the letter is in the word but in the wrong position" << endl;
	cout << "Gray means the letter is not in the word" << endl << endl;
}

void Game::play() {
	vector<string> guesses(6, "    ");

	while (tries < 6) {
		cout << "Round " << tries + 1 << endl;
		string guess;
		cout << "Enter word (5-letters): ";
		cin >> guess;

		if (Grid::stringLength(guess) != 5) {
			cout << "Invalid input. Please enter a 5-letter word." << endl;
			//cout << "Enter word (5-letters): ";
			//cin >> guess;
			continue;
		}

		guesses[tries] = guess;
		tries++;

		for (int i = 0; i < 6; i++) {
			Grid::displayFeedback(word, guesses[i]);
		}
		if (guess == word) {
			cout << "Congratulations! You guessed the word in " << tries << " tries." << endl;
			PerformanceReport::saveScore(tries);
			return;
		}
	}

	cout << "Sorry, you didn't guess the word. The correct word was: " << word << endl;
	PerformanceReport::saveScore(0);
}

void Game::fileError()
{
	cout << "ERROR: Wrong file was opened\n";
}
