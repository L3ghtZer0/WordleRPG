#include "Game.h"
#include "Grid.h"
#include "PerformanceReport.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

Game::Game() : tries(0) {
	ifstream file("fiveLetterWords.txt");
	
	int totalWords = 0;
	string line;
	
	while (getline(file, line)) {
		totalWords++;
	}

	file.clear();
	file.seekg(0);

	srand(42);
	int randomIndex = rand() % totalWords;

	for (int i = 0; i < randomIndex; i++) {
		getline(file, line);
	}
	word = line;
}

string Game::getWord() {
	return word;
}

void Game::rules() {
	cout << "In wordle you need to guess the 5-letter word in 6 or less tries" << endl;
	cout << "Green means the letter is in the correct position" << endl;
	cout << "Yellow means the letter is in the word but in the wrong position" << endl;
	cout << "Gray means the letter is not in the word" << endl;
}

void Game::play() {
	vector<string> guesses(6,"    ");

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