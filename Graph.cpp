#include "pch.h"
#include "Graph.h"
#include "string"
#include <iostream>
#include <iomanip>


Graph::Graph()
{
	
}
Graph::~Graph()
{
}
int Graph::insert(string symbolTable[],int size, string airport)
{
	int i = 0;
	while (i < strSize - 1)
	{
		if (symbolTable[i] == " ")
		{
			symbolTable[i] = airport;
			//cout << "Inserting " << airport << " at position " << i << endl;
			numOfAirports++;
			return i;
			
		}
		else 
			if (symbolTable[i] == airport)
			return i;
		
		i= i +1;
	}

}
void Graph::shortestPath(string symbolTable[], int miles[][size], int costs[][size], string aiport)

{
	
	
	for (int i = 0; i < 20; i++)
	{
		if (aiport == symbolTable[i])
		{
			tablePosition = i;
		}
	}
	// initializes arrays p and d and list l
	rS.push_back(tablePosition);
	for (int i = 0; i < size; i++)
	{
		d[i] = costs[tablePosition][i];
		if (costs[tablePosition][i] == 5000)
		{
			p[i] = 0;
		}
		else
		{
			p[i] = tablePosition;
			l.push_back(i);
		}

	}
	//Step 2
	while (!l.empty())
	{

		/*Loop through l checking it's elements against the elements at that position in d, fidning the element in l taht coresponds the
		lowest element in d*/
		//Step 3
		dvalue = d[(l[0])];
		lposition = 0;
		for (int i = 1; i < l.size(); i++)
		{
			
			if (d[(l[i])] < dvalue)
			{
				dvalue = d[(l[i])];
				lposition = i;
			}
		}
		//adds the  vertex in l with least value in d to reached set, then deletes that vertex from L
		rS.push_back((l[lposition])); 
		tempLvalue = (l[lposition]);
		l.erase(l.begin() + lposition);
		

		//now find all vertexs ajacent to the vertex that was just deleted from L ( make sure to update for ALL ADJACENT VERTEXS), and update
		//d[j] using the algrothim, going for lowest cost not lowest miles
		//tempLvalue = i j = J
		//Step 4
		
		for (int j = 0; j < size; j++)
		{

			
			if (costs[tempLvalue][j] != infinity )
			{
				
				if ((d[tempLvalue] + costs[tempLvalue][j]) < d[j] && j != tablePosition)
				{
					d[j] = ((d[tempLvalue]) + costs[tempLvalue][j]);
					p[j] = tempLvalue;
					l.push_back(j); // check to see if j is already in l if this ends up running slow
				}
			}
				
		}


	}
	
	cout << "Best Price Report " << endl;
	cout <<	setw(60) <<" Connecting Flight Information " << endl;
	cout << "source " << "destination " << "cost " << "mileage " << "src " << "dest " << "cost " << "mileage " << endl;
	cout << "------  " << "---------- " << "---- " << "-------" << "--------------------------------------- " << endl;
	
	//follow the ariport path through p adding them into a stack, then pop each aiport off adding the price and mileage to
	//dedicated variables found through the vertices

	for (int i = 0; i < numOfAirports; i++)
	{
		if (i == tablePosition)
		{

		}
		else
		{
			int check = p[i];
			airportSequence.push_back(i);
			while (check != tablePosition)
			{

				airportSequence.push_back(check);
				check = p[check];
			}
			airportSequence.push_back(tablePosition);
			totalDist(airportSequence, miles);

			printHelper(airportSequence, symbolTable, miles, costs);
			cout << "---------------------------------------------------" << endl;
			airportSequence.clear();
		}
	}

	
}
void Graph::totalDist(vector<int> airportSequence, int miles[][size])
{
	int lead = (airportSequence.size() - 2);
	int follow = (airportSequence.size() - 1);
	int totalDist = 0;
	if (airportSequence.size() > 2)
	{
		
		while (lead != 0)
		{
			totalDist = +miles[(airportSequence[follow])][(airportSequence[lead])];
			lead--;
			follow--;
		};
		
	}

	else
	{
		totalDist = miles[(airportSequence[follow])][(airportSequence[lead])];
	}
	totalMiles = totalDist;
	
		


}
void Graph::printHelper(vector <int> airportSequence, string symboltable[], int miles[][size], int costs[][size])
{

	//prints the steps given to it in the stack that is passed.
	int lead = (airportSequence.size() - 2);
	int follow = (airportSequence.size() - 1);

	cout << symboltable[(airportSequence[follow])] << "       " << symboltable[(airportSequence[0])] << "       " << d[(airportSequence[0])] << "     " << totalMiles
		<< "  " << endl;
	// toDO write if staff incase it is a direct flight ( lead would = airportsequence[0])
	//toDO difference between the two airport sequnces needs to be fixed
	// toDo check the calls to miles and costs to get single flight costs and distance
	// toDO set weight for print statments on connecting flights
	
	while (lead >= 0)
	{
		cout <<setw(35) << symboltable[(airportSequence[follow])] << " -> " << symboltable[(airportSequence[lead])] << "  $" << (costs[(airportSequence[follow])][(airportSequence[lead])])
			<< "  " << (miles[(airportSequence[follow])][(airportSequence[lead])]) << endl;
		lead--;
		follow--;
	}
	airportSequence.clear();
}

	