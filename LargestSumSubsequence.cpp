#include "LargestSumSubsequence.h"

// Constructor of class LargestSumSubsequence
LargestSumSubsequence::LargestSumSubsequence(string file_name) {
	readData(file_name);
}

// Function to read data from the input txt file
void LargestSumSubsequence::readData(string file_name) {
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

// Function to find the largest sum subsequence
void LargestSumSubsequence::find() {
	// Declare variables
	float maxDp = 0;
	int maxIdx = 0;
	float* dp = new float[_n];
	dp[0] = _input_arr[0];
	if (dp[0] < 0) 
		dp[0] = 0;

	for (int i = 1; i < _n; i++) {
		dp[i] = dp[i - 1] + _input_arr[i];
		if (dp[i] < 0) 
			dp[i] = 0;
		if (dp[i] > maxDp) {
			maxDp = dp[i];
			maxIdx = i;
		}
	}

	_maxSum = maxDp;
	int temp = maxIdx;
	while (dp[temp] > 0) {
		float value = _input_arr[temp];
		_maxSubsequence.insert(_maxSubsequence.begin(), value);
		temp--;
	}

	printResult(_maxSubsequence, NULL, _n);
}

// Function to print the result
void LargestSumSubsequence::printResult(vector<float> arr1, float* arr2, int size) {
	if (arr1.size() != 0) {
		int vector_size = arr1.size();
		for (int i = 0; i < vector_size; i++) {
			cout << arr1[i];
			if (i != (size - 1))
				cout << " ";
		}
	}
	if (arr2 != NULL) {
		for (int i = 0; i < size; i++) {
			cout << arr2[i];
			if (i != (size - 1))
				cout << " ";
		}
	}
	cout << endl;
	cout << _maxSum;
	cout << endl;
}