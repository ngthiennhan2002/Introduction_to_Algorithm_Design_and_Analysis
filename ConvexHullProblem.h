#pragma once
#include "Header.h"

struct Point {
	int x;
	int y;
};

struct NextPoint_MinAngle {
	Point nextPoint;
	double minAngle;
};

class ConvexHullProblem {
private:
	int _n;
	vector<Point> _points;
	vector<Point> _convexHull;

public:
	// Constructor
	ConvexHullProblem(string);

	// Methods
	void readData(string);
	double computeAngle(Point, Point);
	Point findFirstExtremePoint(vector<Point>, int&);
	Point findNextExtremePoint(vector<Point>, Point, int&, double&);
	void solve();
	void printResult(vector<Point>, int);
};
