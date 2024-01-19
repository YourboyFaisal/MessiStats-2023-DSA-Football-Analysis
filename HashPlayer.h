#pragma once
#include <iostream>
using namespace std;

class Assist // node for hashing
{

public:
    string name;
    int assists = 0;
    Assist *next = NULL;
    Assist(string playerName, int assistCount) : name(playerName), assists(assistCount), next(nullptr)
    {
        // Initialize the class members with the provided values
    }
};

class hashtable_player
{
public:
    Assist **hasharray = new Assist *[1000]
    { NULL }; // array for hashing

    void insert(Assist *newassist)
    {
        int location = hashfunction(newassist->name);
        if (hasharray[location] == NULL) // if jaga hai udhr khaali
        {
            hasharray[location] = newassist;
        }
        else // uss dabbe pr linkedlist banadi
        {
            Assist *temp = hasharray[location];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp = newassist;
        }
    }

    Assist *search(string search_name)
    {
        int location = hashfunction(search_name);

        Assist *temp = hasharray[location];
        while (temp != NULL)
        {
            if (temp->name == search_name)
            {
                break;
            }
            temp = temp->next;
        }
        return temp;
    }

    int hashfunction(string assist_player)
    {
        long long int hash = 0;
        for (int i = 0; i < assist_player.size(); i++)
        {
            hash = hash + 7 * (int)assist_player[i]; // random formula
        }
        return hash % 1000; // to stay in array bounds
    }
};