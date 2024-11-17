#include "PerformanceReport.h"
#include <iostream>
#include <fstream>

using namespace std;

void PerformanceReport::displayReport() {
	ifstream statsFile("wordleStats.txt");
	if (!statsFile) {
		cout << "No games have been played yet." << endl;
		return;
	}


	int totalGames = 0, totalWins = 0, totalTries = 0, score;
	while (statsFile >> score) {
		totalGames++;
		if (score > 0) {
			totalWins++;
			totalTries += score;
		}
	}

	if (totalGames == 0) {
		cout << "No games have been played yet." << endl;
		return;
	}

	double winPercentage = (double(totalWins) / totalGames) * 100;
	double averageTries = totalWins > 0 ? (double(totalTries) / totalWins) : 0;

	cout << "\nPerformance Report:" << endl;
	cout << "Games Played: " << totalGames << endl;
	cout << "Win Percentage: " << winPercentage << "%" << endl;
	cout << "Average Tries (for wins): " << averageTries << endl << endl;
}

void PerformanceReport::saveScore(int score) {
	ofstream statsFile("wordleStats.txt", ios::app);
	if (!statsFile) {
		cerr << "Error: Unable to save stats." << endl;
		return;
	}
	statsFile << score << endl;
}
