#include "ChangeMakingProblem.h"

// Constructor of the ChangeMakingProblem class
ChangeMakingProblem::ChangeMakingProblem(string file_name) {
	readData(file_name);
}

// Function to read data from the text file
void ChangeMakingProblem::readData(string file_name) {
	// Declare and open the txt file
	fstream file;
	file.open(file_name);

	// Check if the file is read successfully
	if (!file) {
		cout << "Failed to open the input file." << endl;
		return;
	}

	// Read all numbers in the file
	int temp = 0;
	vector<int> data;

	while (!file.eof()) {
		file >> temp;
		data.push_back(temp);
	}

	// Get the money number (last element of the vector)
	int number_of_deno = data.size() - 1;
	_money = data[number_of_deno];
	data.pop_back();
	_denomination = data;

	// Close the txt file
	file.close();
}

// Function to solve the change-making problem
void ChangeMakingProblem::solve() {
	int size = _denomination.size();
	int temp_money = _money;
	int* res = new int[size];

	for (int i = 0; i < size; i++) {
		res[i] = temp_money / _denomination[i];
		temp_money %= _denomination[i];
	}

	printResult(res, size);
}

// Function to print the result
void ChangeMakingProblem::printResult(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << _denomination[i] << ": " << arr[i] << endl;
	}
	cout << endl;
}