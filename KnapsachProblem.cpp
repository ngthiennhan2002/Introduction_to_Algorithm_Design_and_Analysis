#include "KnapsachProblem.h"

// Constructor
Knapsach::Knapsach(string file_name) {
	readData(file_name);
}

// Function to read data from the input txt file
void Knapsach::readData(string file_name) {
	// Declare and open the txt file
	fstream file;
	file.open(file_name);

	// Check if the file is read successfully
	if (!file) {
		cout << "Failed to open the input file." << endl;
		return;
	}

	// Read first row (weight) and second row (n)
	file >> _w >> _n;

	// Read third packages
	for (int i = 0; i < _n; i++) {
		int weight, value; Package p;
		file >> weight >> value;
		p.w = weight; p.v = value;
		_input.push_back(p);
	}

	// Close the txt file
	file.close();
}

// Function to print out the result
void Knapsach::printResult(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != (arr.size() - 1))
			cout << " ";
	}
	cout << endl;
}