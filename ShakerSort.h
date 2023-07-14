#pragma once
#include "Header.h"

class ShakerSort {
private:
	int _n;
	float* _input_arr;
public:
	// Constructor
	ShakerSort(string);

	// Getter
	int getSize() { return _n; }
	float* getInputArray() { return _input_arr;	}

	// Methods
	void readData(string);
	void swap(float&, float&);
	void printArray(float*);
	void sort();
};

