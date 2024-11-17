#ifndef GRID_H
#define GRID_H

#include <string>
using namespace std;

class Grid {
	public:
		static void displayFeedback(const string& word, const string& guess);
		static int stringLength(const string& str);
		static bool charExistsInString(const string& str, char ch);
};

#endif
