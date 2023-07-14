#include "TravelingSalesmanProblem.h"

// Constructor
TravelingSalesman::TravelingSalesman(string file_name) {
	readData(file_name);
}

// Function to read data from the input txt file
void TravelingSalesman::readData(string file_name) {
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

	// Read second row (unsorted array)
	for (int i = 0; i < _n; i++) {
		int fromCity, toCity, distance; CitiesDistance citiesDistance;
		file >> fromCity >> toCity >> distance;
		citiesDistance.fromCity = fromCity;
		citiesDistance.toCity = toCity;
		citiesDistance.distance = distance;
		_input_cities.push_back(citiesDistance);
	}

	// Close the txt file
	file.close();
}

// Function to remove duplicates in a vector
void TravelingSalesman::removeDuplicates(vector<int>& arr) {
	vector<int> temp;
	temp.push_back(arr[0]);
	for (int i = 0; i < arr.size(); i++) {
		bool dup = false;
		for (int j = 0; j < temp.size(); j++) {
			if (arr[i] == temp[j])
				dup = true;
		}
		if (!dup)
			temp.push_back(arr[i]);
	}
	arr = temp;
}

// Function to swap two integers
void TravelingSalesman::swap(vector<int> &arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


// Function to find all permutations of an array
void TravelingSalesman::permutations(vector<int>& arr, int left, int right, vector<int>& currentMinPath, int& minPath) {
	if (left == right) {
		// Compute the smallest path solving the problem
		int computedDistance = 0;
		vector<int> currentPath = computePath(arr, computedDistance);
		printResult(currentMinPath, computedDistance);
		if (computedDistance < minPath) {
			minPath = computedDistance;
			currentMinPath = currentPath;
		}
	}
	else {
		for (int i = left; i <= right; i++) {
			swap(arr, left, i);
			permutations(arr, left + 1, right, currentMinPath, minPath);
			swap(arr, left, i);
		}
	}
}

// Function to calculate minimum path
vector<int> TravelingSalesman::computePath(vector<int> arr, int& pathDistance) {
	int totalDistance = 0;
	int firstCity = _input_cities[0].fromCity;
	arr.insert(arr.begin(), firstCity);
	arr.push_back(firstCity);
	for (int i = 0; i < arr.size() - 1; i++) {
		bool flag = false;
		for (int j = 0; j < _input_cities.size(); j++) {
			int fromCity = _input_cities[j].fromCity;
			int toCity = _input_cities[j].toCity;
			int distance = _input_cities[j].distance;
			if ((arr[i] == fromCity && arr[i + 1] == toCity) || (arr[i] == toCity && arr[i + 1] == fromCity)) {
				totalDistance += distance;
				flag = true;
			}
		}
		if (flag == false) { 
			totalDistance = -1;
			break; 
		}
	}
	pathDistance = totalDistance;
	printResult(arr, pathDistance);
	arr.pop_back(); // delete a duplicate of the first city at the end of the vector
	return arr;
}

// Function to solve the problem
void TravelingSalesman::solve() {
	vector<int> cities_list;
	cities_list.push_back(_input_cities[0].fromCity);
	cities_list.push_back(_input_cities[0].toCity);
	for (int i = 0; i < _n; i++) {
		cities_list.push_back(_input_cities[i].fromCity);
		cities_list.push_back(_input_cities[i].toCity);
	}
	removeDuplicates(cities_list);
	cities_list.erase(cities_list.begin());

	// Get permutations of all cities (except the first city)
	int minPath = 1000000;
	vector<int> currentMinPath;
	int size = cities_list.size();
	permutations(cities_list, 0, size - 1, currentMinPath, minPath);

	// Print out the result
	printResult(currentMinPath, minPath);
}

// Function to print out the result
void TravelingSalesman::printResult(vector<int> arr, int distance) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != (arr.size() - 1))
			cout << " ";
	}
	cout << endl;
	cout << distance << endl;
}