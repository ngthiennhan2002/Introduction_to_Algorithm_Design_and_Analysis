#include "Header.h"
#include "ShakerSort.h"
#include "LargestSumSubsequence.h"
#include "ChangeMakingProblem.h"
#include "ConvexHullProblem.h"
#include "TravelingSalesmanProblem.h"

int main() {
	// Question 1: Shaker Sort
	cout << "Q1:" << endl;
	string file_name_1 = "input_1.txt";
	ShakerSort shakerSort(file_name_1);
	shakerSort.sort();

	cout << endl;
	
	// Question 2: Find the subsequence with largest sum of elements in an given real array
	// Using Dynamic programming version
	cout << "Q2:" << endl;
	string file_name_2 = "input_2.txt";
	LargestSumSubsequence largestSumSubsequence(file_name_2);
	largestSumSubsequence.find();

	cout << endl;

	// Question 3: The change-making problem
	cout << "Q3:" << endl;
	string file_name_3 = "input_3.txt";
	ChangeMakingProblem changeMakingProblem(file_name_3);
	changeMakingProblem.solve();

	cout << endl;

	// Question 4: Convex-hull problem
	cout << "Q4:" << endl;
	string file_name_4 = "input_4.txt";
	ConvexHullProblem convexHullProblem(file_name_4);
	convexHullProblem.solve();

	cout << endl;

	// Question 5: Traveling Salesman problem
	cout << "Q5:" << endl;
	string file_name_5 = "input_5.txt";
	TravelingSalesman travelingSalesman(file_name_5);
	travelingSalesman.solve();

	return 1;
}