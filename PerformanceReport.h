#ifndef PERFORMANCEREPORT_H
#define PERFORMANCEREPORT_H
// Class specification file for PerformanceReport class
class PerformanceReport {
	public:
		// Static functions to ensure encapsulation and mitigate accidental changes
		static void displayReport();
		static void saveScore(int score);
};

#endif
