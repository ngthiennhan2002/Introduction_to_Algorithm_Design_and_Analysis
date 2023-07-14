#pragma once
#include "Header.h"

class ChangeMakingProblem {
private:
	int _money;
	vector<int> _denomination;

public:
	// Constructor
	ChangeMakingProblem(string);

	// Methods
	void readData(string);
	void solve();
	void printResult(int*, int);
};
