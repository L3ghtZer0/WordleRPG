// Header Files
#include "Grid.h"
#include <Windows.h>
#include <iostream>
#include <unordered_map>

// namespace
using namespace std;

// Colors for wordle
const int GREEN = 0x2F, YELLOW = 0x6F, GRAY = 0x8F, RED = 0x4F, RESET = 0x07;

// Function to change color
void setConsoleColor(int color) {
	HANDLE COUT_H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(COUT_H, color);
}

// get the string length 
int Grid::stringLength(const string& str) {
	int length = 0; // initialize
	while (str[length] != '\0') {
		length++; 
	}
	return length;
}

// check if the letter is in the string
bool Grid::charExistsInString(const string& str, char ch) {
	for (int i = 0; i < stringLength(str); i++) {
		if (str[i] == ch) { // if the letter is in the string
			return true; // return true
		}
	}
	return false; // if that is not satisfied return false
}

// display feedback via the grid
void Grid::displayFeedback(const string& word, const string& guess) {

	// left line for formatting
	cout << "|";

	// to get duplicate numbers
	unordered_map<char, int> letterCount;
	for (char ch : guess) {
		letterCount[ch]++;
	}

	// checking if the letter is correct
	for (int i = 0; i < stringLength(word); i++) {
		if (guess[i] == ' ') {
			setConsoleColor(RESET); // if letter hasn't been put yet then put the default
		}
		else if (guess[i] == word[i]) { // if the letter is in the word and in the right spot
			setConsoleColor(GREEN); // mark it off as green
		}
		else if (charExistsInString(word, guess[i])) {
			setConsoleColor(YELLOW); // if the letter is in the word but not in the right space, mark it as yellow
			if (charExistsInString(word, guess[i]) && letterCount[guess[i]] > 1)
			{
				setConsoleColor(RED); // if the letter is in the word, but is put two times, mark them both red
			}
		}
		// If it's a repeat letter
		else {
			setConsoleColor(GRAY); // if none of those are true, then mark it as gray
		}
		cout << " " << guess[i] << " "; // print out the guess with the proper color
			setConsoleColor(RESET);  // reset
			cout << "|"; // right border
	}
	cout << "\n---------------------" << endl; // line for formatting
}
