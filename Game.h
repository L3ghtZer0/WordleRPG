#ifndef GAME_H
#define GAME_H

// include string and use std namespace
#include <string>
using namespace std;

// define Game Class
class Game {
	private: // variables
		string word;
		int tries;
	public: // function prototypes
		Game();
		void rules();
		string getWord();
		void play();
};

#endif
