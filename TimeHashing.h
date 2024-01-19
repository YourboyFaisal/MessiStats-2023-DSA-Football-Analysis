#pragma once
#include <iostream>
#include "singlyLinkedList.h"
#include "teamLinkedList.h"
#include "TeamBST.h"
#include "Source.h"
#include <cstring>
#include <string>

using namespace std;

class hashtable_minute
{
public:
	FootballMatch **hasharray = new FootballMatch *[10]
	{ NULL };

	void insert(FootballMatch *newRecord)
	{

		// the hash value will get stored in he location
		int location = hashfunction(newRecord->minute);

		// if the location is null then it assign the new record
		if (hasharray[location] == NULL)
		{
			hasharray[location] = newRecord;
		}
		// else it traverse the ll till that location and then append the new record
		else
		{
			FootballMatch *loc = hasharray[location];
			FootballMatch *ploc = NULL;

			while (loc != NULL)
			{
				ploc = loc;
				loc = loc->minutenext;
			}
			ploc->minutenext = newRecord;
		}
	}

	FootballMatch *search(string minute)
	{
		// looks for record for the given parameter minute in the hash table
		// record returned is saved as location and printed on the console
		int location = hashfunction(minute);
		cout << location << endl;

		FootballMatch *loc = hasharray[location];
		FootballMatch *ploc = NULL;

		// it starts to traverse the ll at that location until it find
		while (loc != NULL && loc->minute != minute)
		{
			ploc = loc;
			loc = loc->next;
			;
		}

		return loc;
	}

	void printHashChain(int hash)
	{

		//	takes hash as a parameter which is an index in hash array where the ll is stored
		// pointer loc is initoalized with that particular hash index

		FootballMatch *loc = hasharray[hash];
		// loop traverse until the end of ll and prints the attributes ofthe object
		while (loc != NULL)
		{
			cout << loc->season << ", " << loc->competition << ", " << loc->matchday << ", " << loc->date << ", " << loc->venue << ", " << loc->club << ", " << loc->opponent << ", " << loc->result << ", " << loc->playing_position << ", " << loc->minute << ", " << loc->at_score << ", " << loc->type << ", " << loc->goal_assist << endl
				 << endl;
			loc = loc->minutenext;
		}
	}

	int hashfunction(string minute)
	{
		// if the length is greater than 1 then it will take the first character of the string and convert it into integer and returns it as a hash value
		if (minute.length() > 1)
		{
			return stoi(minute.substr(0, 1));
		}
		// else it returns 0
		else
		{
			return 0;
		}
	}
};
