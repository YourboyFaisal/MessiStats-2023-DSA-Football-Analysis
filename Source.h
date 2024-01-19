#pragma once
#include <iostream>
#include "singlyLinkedList.h"
#include "TimeHashing.h"
#include "HashPlayer.h"
#include <fstream>
#include <cstdlib>

using namespace std;

class Solution
{
    hashtable_player *table_player = new hashtable_player;
    hashtable_minute *table_minute = new hashtable_minute;

    void Parser(singlyLinkedList &list) // makes singlylinkedlist and time hashing
    {
        ifstream file("data.csv"); // only read mode
        string line;
        getline(file, line); // takes heading in csv file and discards (Season, Competition, Matchday, Date, Venue, C..)
        while (getline(file, line)) // until EOF
        {
            // take out words from the line and make a node
            FootballMatch *newNode = new FootballMatch();

            int count = 1;
            string word = "";

            for (int i = 0; i <= line.size(); i++)
            {
                if (line[i] != ',' && i != line.size())
                {
                    word += line[i];
                }
                else
                {
                    if (count == 1)
                    {
                        newNode->season = word;
                    }
                    else if (count == 2)
                    {
                        newNode->competition = word;
                    }
                    else if (count == 3)
                    {
                        newNode->matchday = word;
                    }
                    else if (count == 4)
                    {
                        newNode->date = word;
                    }
                    else if (count == 5)
                    {
                        newNode->venue = word;
                    }
                    else if (count == 6)
                    {
                        newNode->club = word;
                    }
                    else if (count == 7)
                    {
                        newNode->opponent = word;
                    }
                    else if (count == 8)
                    {
                        newNode->result = word;
                    }
                    else if (count == 9)
                    {
                        newNode->playing_position = word;
                    }
                    else if (count == 10)
                    {
                        newNode->minute = word;
                    }
                    else if (count == 11)
                    {
                        newNode->at_score = word;
                    }
                    else if (count == 12)
                    {
                        newNode->type = word;
                    }
                    else if (count == 13)
                    {
                        newNode->goal_assist = word;
                    }
                    count++;
                    word = "";
                }
            }
            // inserting in singly linkedlist
            if (list.head == NULL)
            {
                list.head = newNode;
                list.tail = newNode;
            }
            else
            {
                list.tail->next = newNode;
                list.tail = newNode;
            }

            // inserting in hashtable_player
            Assist *temp = table_player->search(newNode->goal_assist);
            if (temp == NULL) //table men node not found
            {
                Assist *temp = new Assist(newNode->goal_assist, 1);
                table_player->insert(temp);
            }
            else
            {
                temp->assists++; // 2
            }

            // timehashing
            table_minute->insert(newNode);
        }

    }

public:
    void MainMenu()
    {
        char choice = 'w';
        singlyLinkedList list;
        Parser(list);
        TeamList teams;
        teams.CreateList(list);
        // teams.Print();
        TeamTree teamTree;
        teamTree.root = teamTree.sortedListtoBST(teams.head);
        // teamTree.InOrderTrav(teamTree.root);
        while (choice != '5')
        {
            cout << endl
                 << "Please select an option:" << endl
                 << endl;
            cout << "\t1. Print all of Messi's goals in his career." << endl;
            cout << "\t2. Search a team that Messi has scored against." << endl;
            cout << "\t3. Search a player to get his records on assisting Messi." << endl;
            cout << "\t4. Enter the minute range in which you want to see Messi's goals." << endl;
            cout << "\t5. Exit the program." << endl;
            cout << endl
                 << endl
                 << "\tChoice: ";

            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case ('1'):
            {
                list.print();
            };
            break;
            case ('2'):
            {
                string s;
                cout << "Insert which team you want to search about:" << endl;
                getline(cin, s);

                teamTree.SearchTeam(s);

                if (teamTree.loc != NULL)
                {
                    cout << endl
                         << endl;
                    cout << "Team: " << teamTree.loc->teamname << endl;
                    cout << "Goals scored against them: " << teamTree.loc->goalsscored << endl;
                }

                else
                {
                    cout << "Team not found!" << endl;
                }
            };
            break;
            case ('3'):
            {
                string s;
                cout << "Which player you want to search about: ";
                getline(cin, s);
                Assist *temp = table_player->search(s);
                if (temp != NULL)
                {
                    cout << endl
                         << endl
                         << "Player: " << s << endl
                         << "Assists: " << temp->assists << endl;
                }
                else
                {
                    cout << endl
                         << endl
                         << "Player: " << s << endl
                         << "Assists: 0" << endl;
                }
            };
            break;
            case ('4'):
            {
                int min1;
                cout << "Enter the minute range that you want to see the records of the goals:" << endl;
                cout << "\t0. 0 to 10 minutes" << endl;
                cout << "\t1. 10 to 20 minutes" << endl;
                cout << "\t2. 20 to 30 minutes" << endl;
                cout << "\t3. 30 to 40 minutes" << endl;
                cout << "\t4. 40 to 50 minutes" << endl;
                cout << "\t5. 50 to 60 minutes" << endl;
                cout << "\t6. 60 to 70 minutes" << endl;
                cout << "\t7. 70 to 80 minutes" << endl;
                cout << "\t8. 80 to 90 minutes" << endl;
                cout << "\t9. 90 or more minutes" << endl;

                cin >> min1;
                table_minute->printHashChain(min1);
            };
            break;
            case ('5'):
            {
                cout << "\t\t\tDSA Project " << endl
                     << "\t\tFaisal Shahid (CTAI-011)" << endl
                     << "\t\t Hunaiza Khan (CTAI-007)";
                break;
            };
            break;
            default:
                cout << "Invalid action selected, please enter again!" << endl;
            }
        }
    }
};