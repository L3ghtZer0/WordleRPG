#ifndef GRID_H
#define GRID_H

// include string and use std namespace
#include <string>
using namespace std;

// define Grid Class
class Grid {
	public: // function prototypes
		static void displayFeedback(const string& word, const string& guess);
		static int stringLength(const string& str);
		static bool charExistsInString(const string& str, char ch);
};

#endif
