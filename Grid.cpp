#include "Grid.h"
#include <Windows.h>
#include <iostream>
#include <unordered_map>
using namespace std;

const int GREEN = 0x2F, YELLOW = 0x6F, GRAY = 0x8F, RESET = 0x07;

void setConsoleColor(int color) {
	HANDLE COUT_H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(COUT_H, color);
}

int Grid::stringLength(const string& str) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

bool Grid::charExistsInString(const string& str, char ch) {
	for (int i = 0; i < stringLength(str); i++) {
		if (str[i] == ch) {
			return true;
		}
	}
	return false;
}

void Grid::displayFeedback(const string& word, const string& guess) {
	cout << "---------------------" << endl;
	cout << "|";

	unordered_map<char, int> letterCount;
    	for (char ch : guess) {
        letterCount[ch]++;
    	}
	
	for (int i = 0; i < stringLength(word); i++) {
		if (guess[i] == word[i]) {
			setConsoleColor(GREEN);
		}
		else if (charExistsInString(word, guess[i])) {
			setConsoleColor(YELLOW);
		}
		else if (guess[i] == NULL) {
			setConsoleColor(RESET);
		}
		// If it's a repeat letter
        	else if (charExistsInString(word, letterCount[guess[i]] > 1) {
            		setConsoleColor(RED);
        	}
		else {
			setConsoleColor(GRAY);
		}
		cout << " " << guess[i] << " ";
		setConsoleColor(RESET);
		cout << "|";
	}
	cout << "\n---------------------" << endl;
}
