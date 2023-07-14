#pragma once
#include "Header.h"

struct Package {
	int w;
	int v;
};

class Knapsach {
private:
	int _w;
	int _n;
	vector<Package> _input;
	vector<vector<Package>> _output;
	int _totalValue;

public:
	// Constructor
	Knapsach(string);

	// Methods
	void readData(string);
	void permutations(vector<int>&, int, int);
	void printResult(vector<int>);
};