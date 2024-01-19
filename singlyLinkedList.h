#pragma once
#include <iostream>
using namespace std;

class FootballMatch // Node for Linkedlist
{
public:
    string season;
    string competition;
    string matchday;
    string date;
    string venue;
    string club;
    string opponent;
    string result;
    string playing_position;
    string minute;
    string at_score;
    string type;
    string goal_assist;
    FootballMatch *next;
    FootballMatch *minutenext;

    FootballMatch()
    {
        next = NULL;
        minutenext = NULL;
    }
};

class singlyLinkedList
{
public:
    FootballMatch *head;
    FootballMatch *tail;

    singlyLinkedList(): head(NULL),tail(NULL){}
    void print()
    {
        FootballMatch *temp = head;
        while (temp != NULL)
        {
            cout << temp->season << ", " << temp->competition << ", " << temp->matchday << ", " << temp->date << ", " << temp->venue << ", " << temp->club << ", " << temp->opponent << ", " << temp->result << ", " << temp->playing_position << ", " << temp->minute << ", " << temp->at_score << ", " << temp->type << ", " << temp->goal_assist << endl
                 << endl;
            temp = temp->next;
        }
    }
};