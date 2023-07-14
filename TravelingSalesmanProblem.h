#pragma once
#include "Header.h"

struct CitiesDistance {
	int fromCity;
	int toCity;
	int distance;
};

class TravelingSalesman {
private:
	int _n;
	vector<CitiesDistance> _input_cities;
	vector<CitiesDistance> _output_cities;

public:
	// Constructor
	TravelingSalesman(string);

	// Methods
	void readData(string);
	void swap(vector<int>&, int, int);
	void permutations(vector<int>&, int, int, vector<int>&, int&);
	vector<int> computePath(vector<int>, int&);
	void removeDuplicates(vector<int>&);
	void solve();
	void printResult(vector<int>, int);
};