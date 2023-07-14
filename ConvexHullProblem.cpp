#include "ConvexHullProblem.h"

// Constructor of class LargestSumSubsequence
ConvexHullProblem::ConvexHullProblem(string file_name) {
	readData(file_name);
}

// Function to read data from the input txt file
void ConvexHullProblem::readData(string file_name) {
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

	// Read points in text file
	for (int i = 0; i < _n; i++) {
		int x, y; Point p;
		file >> x >> y;
		p.x = x; p.y = y;
		_points.push_back(p);
	}

	// Close the txt file
	file.close();
}

// Function to choose first extreme point
Point ConvexHullProblem::findFirstExtremePoint(vector<Point> list, int& current_pos) {
	int min_y = 100000; int min_x = 100000;
	int pos = 0;
	int size = list.size();
	for (int i = 0; i < size; i++) {
		if (list[i].y < min_y) {
			min_y = list[i].y;
		}
	}

	for (int i = 0; i < size; i++) {
		if (list[i].y == min_y && list[i].x < min_x) {
			min_x = list[i].x;
			pos = i;
		}
	}

	current_pos = pos;
	return list[pos];
}

// Function to compute angle of two points
double ConvexHullProblem::computeAngle(Point a, Point b) {
	double angle = atan2(b.y - a.y, b.x - a.x);
	if (angle < 0) {
		angle += 2 * PI;
	}
	return angle;
}

// Function to find next extreme point
Point ConvexHullProblem::findNextExtremePoint(vector<Point> S, Point current_point, int& currentPos, double& currentAngle) {
	double minAngle = 2 * PI;
	Point nextPoint;

	// Copy S vector, delete current point
	vector<Point> temp;
	for (int i = 0; i < S.size(); i++) {
		if (i == currentPos) continue;
		temp.push_back(S[i]);
	}

	// Find the next point with the smallest angle
	for (int i = 0; i < temp.size(); i++) {
		Point p = temp[i];
		double angle = computeAngle(current_point, p);
		if (angle < minAngle && angle >= currentAngle) {
			nextPoint = p;
			minAngle = angle;
		}
	}

	// Get the position of the next point
	for (int i = 0; i < S.size(); i++) {
		if (nextPoint.x == S[i].x && nextPoint.y == S[i].y)
			currentPos = i;
	}

	currentAngle = minAngle;

	return nextPoint;
}

// Function to solve the Convex-hull problem
void ConvexHullProblem::solve() {
	int current_pos = 0;
	Point firstExtremePoint = findFirstExtremePoint(_points, current_pos);
	_convexHull.push_back(firstExtremePoint);
	double currentAngle = 0;
	Point currentPoint = firstExtremePoint;
	Point nextExtremePoint;

	while (true) {
		nextExtremePoint = findNextExtremePoint(_points, currentPoint, current_pos, currentAngle);
		if (firstExtremePoint.x == nextExtremePoint.x && firstExtremePoint.y == nextExtremePoint.y)
			break;
		_convexHull.push_back(nextExtremePoint);
		currentPoint = nextExtremePoint;
	}

	printResult(_convexHull, _convexHull.size());
}

// Function to print out a list of points
void ConvexHullProblem::printResult(vector<Point> list, int size) {
	for (int i = 0; i < size; i++) {
		cout << "(" << list[i].x << "," << list[i].y << ")";
	}
	cout << endl;
}