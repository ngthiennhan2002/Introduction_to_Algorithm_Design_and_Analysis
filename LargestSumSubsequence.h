#pragma once
#include "Header.h"

class LargestSumSubsequence {
private:
	int _n;
	float* _input_arr;
	vector<float> _maxSubsequence;
	float _maxSum;

public:
	// Constructor
	LargestSumSubsequence(string);

	// Methods
	void readData(string);
	void find();
	void printResult(vector<float>, float*, int);
};