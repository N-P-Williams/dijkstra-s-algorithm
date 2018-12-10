#pragma once
#include "string"
#include "vector"
#include <stack>
using namespace std;
class Graph
{
public:
	static const int size = 10;
	static const int strSize = size * 2;
	Graph();
	~Graph();
	int insert(string symbolTable[], int size, string airport);
	void shortestPath(string symbolTable[], int miles[][size], int costs[][size], string airport);
	void printHelper(vector <int> airportSequence, string symbolTable[], int miles[][size], int costs[][size]);
	void totalDist(vector<int> airportSequnece, int miles[][size]);
private:
	int mile, cost;
	int lposition, dvalue, tempLvalue, totalMiles;
	const int infinity = 5000;
	int d[size];
	int p[size];
	vector <int> l;
	vector <int> rS;
	vector <int> airportPath;
	int numOfAirports;
	vector <int> airportSequence;
	int tablePosition; //the position of the starting airport in the matrices.

	
};

