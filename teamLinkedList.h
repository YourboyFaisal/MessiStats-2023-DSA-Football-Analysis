#pragma once
#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

class Team
{
public:
    string team;
    int goals;
    Team *next;
    Team(string name, int g) : team(name), goals(g), next(NULL) {}
};

class TeamList // sorted LL with team names (lexicographically)
{
public:
    Team *head;
    Team *tail;
    Team *loc;
    Team *prev;

    TeamList()
    {
        head = NULL;
        tail = NULL;
        loc = NULL;
        prev = NULL;
    }
    void Search(string searchname) // loc jisko search kr rhe usko point krega end men
    {
        if (head == NULL)
        {
            return;
        }
        loc = head;
        while (loc != NULL && loc->team < searchname)
        {
            prev = loc;
            loc = loc->next;
        }
        if (loc != NULL && loc->team != searchname) // traverse krliya but nhi mila
        {
            loc = NULL;
        }
    }
    void CreateList(singlyLinkedList &list)
    {
        FootballMatch *temp = list.head;

        while (temp != NULL) // traversing football wali LL
        {
            Search(temp->opponent);
            if (loc != NULL) // found a node in search function
            {
                loc->goals++;
            }
            else // either the linkedlist is empty or the teamnode wasnt found
            {
                Team *newteam = new Team(temp->opponent, 1); // making a new node to insert
                if (tail == NULL)                            // LL is empty
                {
                    head = newteam;
                    tail = newteam;
                }
                else
                {
                    if (prev == NULL) // insert the node at the start
                    {
                        newteam->next = head;
                        head = newteam;
                    }
                    else if (prev == tail) // insert the node at the tail
                    {
                        tail->next = newteam;
                        tail = newteam;
                    }
                    else // insert the node in middle
                    {
                        newteam->next = prev->next;
                        prev->next = newteam;
                    }
                }
            }
            temp = temp->next;
        }
    }

    void Print()
    {
        Team* temp = head;
        while (temp != NULL)
        {
            cout << temp->team << ", " << temp->goals << " " << endl;
            temp = temp->next;
        }
    }
};