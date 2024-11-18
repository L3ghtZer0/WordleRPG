// Header files
#include "PerformanceReport.h"
#include <iostream>
#include <fstream>

// namespace
using namespace std;

// display Report if the user chooses it
void PerformanceReport::displayReport() {

	// open the wordleStats.txt
	ifstream statsFile("wordleStats.txt");

	// if the file cannot be opened yet print that no games have been played then return
	if (!statsFile) {
		cout << "No games have been played yet." << endl;
		return;
	}

	// initialize totalGames, totalWins, totalTries, and score
	int totalGames = 0, totalWins = 0, totalTries = 0, score;

	// while the statsFile takes in the score
	while (statsFile >> score) {
		totalGames++; // increment the total games
		if (score > 0) { // if the score is over 0
			totalWins++; // increment total wins
			totalTries += score; // add the score to totalTries
		}
	}

	// if the totalGames played equals 0  then print out that no games have been played yet
	if (totalGames == 0) {
		cout << "No games have been played yet." << endl;
		return;
	}

	// make a variable containing the win percentage across all games
	double winPercentage = (double(totalWins) / totalGames) * 100;

	// a variable containing the average amount of tries across all games
	double averageTries = totalWins > 0 ? (double(totalTries) / totalWins) : 0;

	// print out the performance report
	cout << "\nPerformance Report:" << endl;
	cout << "Games Played: " << totalGames << endl;
	cout << "Win Percentage: " << winPercentage << "%" << endl;
	cout << "Average Tries (for wins): " << averageTries << endl << endl;
}

// save the score to wordle stats
void PerformanceReport::saveScore(int score) {
	ofstream statsFile("wordleStats.txt", ios::app);
	if (!statsFile) {
		cerr << "Error: Unable to save stats." << endl;
		return;
	} 
	// send the score to wordleStats.txt
	statsFile << score << endl;
}
