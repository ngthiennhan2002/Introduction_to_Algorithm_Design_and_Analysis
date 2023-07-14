#include "ShakerSort.h"

// Constructor of Shaker Sort class
ShakerSort::ShakerSort(string file_name) {
	readData(file_name);
}

// Function to read the data from the input file
void ShakerSort::readData(string file_name) {
	// Declare and open the txt file
	fstream file;
	file.open(file_name);

	// Check if the file is read successfully
	if (!file) {
		cout << "Failed to open the input file." << endl;
		return;
	}

	// Read first row (n)
	file >> _n;

	// Declare in-and-out arrays' based on size n
	_input_arr = new float[_n];

	// Read second row (unsorted array)
	for (int i = 0; i < _n; i++) {
		file >> _input_arr[i];
	}

	// Close the txt file
	file.close();
}

// Function to print an array
void ShakerSort::printArray(float* arr) {
	for (int i = 0; i < _n; i++) {
		cout << arr[i];
		if (i != (_n - 1)) {
			cout << " ";
		}
	}
	cout << endl;
}

// Function to swap two numbers
void ShakerSort::swap(float& a, float& b) {
	float temp = a;
	a = b;
	b = temp;
}

// Function to sort ascendingly the input array
void ShakerSort::sort() {
	int left_border = 0;
	int right_border = _n - 1;
	for (int i = left_border; i < right_border; i++) {
		for (int j = right_border; j > i; j--) {
			if (_input_arr[j] < _input_arr[j - 1]) {
				swap(_input_arr[j], _input_arr[j - 1]);
			}
		}

		left_border = i;
		right_border = _n - 1 - i;
		for (int k = left_border; k < right_border; k++) {
			if (_input_arr[k] > _input_arr[k + 1]) {
				swap(_input_arr[k], _input_arr[k + 1]);
			}
		}
	}

	// Print the result
	printArray(_input_arr);
}