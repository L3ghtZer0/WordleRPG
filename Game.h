#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;

class Game {
	private:
		string word;
		int tries;
	public:
		Game();
		void rules();
		string getWord();
		void play();
};

#endif
