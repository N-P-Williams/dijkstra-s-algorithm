

#include "pch.h"
#include <iostream>
#include "string"
#include "fstream"
#include "Graph.h"
#include <algorithm>
using namespace std;


struct alphabetOrder
{
	string airportName;
	int orgLocation;
};

int main()
{
	
	string fileName;
	fstream myFile;
	string departure, destination, airport;
	int mile, cost;
	static const int size = 10;
	static const int strSize = 2 * size;
	int miles[size][size];
	int costs[size][size];
	string symbolTable[strSize];
	alphabetOrder orderedsymbolTable[strSize];
	int infinity = 5000;
	Graph myGraph;
	int i, j;

	

	for (int i = 0; i <= size - 1; i++)
	{
		for (int j = 0; j <= size - 1; j++)
		{
			miles[i][j] = infinity;
			costs[i][j] = infinity;
		}
	}

	for (int i = 0; i < strSize; i++)
	{
		symbolTable[i] = " ";
	}
	
	cout << "Please enter a file name" << endl;
	cin >> fileName;
	myFile.open(fileName.c_str());
	if (myFile.fail())
	{
		cout << "Error Opening " << fileName << endl;
		return 1;
	}
	cout << "Contents of data file " << endl;

	while (!myFile.eof())
	{
		myFile >> departure >> destination >> mile >> cost;
		i = myGraph.insert(symbolTable, strSize, departure);
		j = myGraph.insert(symbolTable, strSize, destination);
		 miles[i][j] = mile;
		 costs[i][j] = cost;
		cout << departure << "  " << destination << "  " << mile << "  " << cost << endl;
	}
	myFile.close();


	/*populates an array of structs containg the airport names and the orginal locations
	they had in symbol table, find a way to sort them bast on airport name alpabetically, so
	you can iterate through this array to find the order and still have the numbers to use for the matrix*/
	
	/*for (int i = 0; i < strSize; i++)
	{
		orderedsymbolTable[i].airportName = symbolTable[i];
		orderedsymbolTable[i].orgLocation = i;



	} */
	
	while (airport != "QUIT")
	{
	
	
		cout << "Please enter a source airport abbreviation or type quit if you wish to quit " << endl;
		cin >> airport;
		transform(airport.begin(), airport.end(), airport.begin(), ::toupper);
		if (airport == "QUIT")
		{
			system("pause");
			return 0;
		}
		myGraph.shortestPath(symbolTable, miles, costs, airport);
		
	}
	
	
	

	

	system("pause");
	return 0;
}

