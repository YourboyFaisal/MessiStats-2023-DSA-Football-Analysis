#pragma once
#include <iostream>
#include <string>
#include "teamLinkedList.h"

using namespace std;

class TeamTreeNode
{
public:
    // binary tree with left righ child and two attributes
    string teamname;
    int goalsscored;
    TeamTreeNode *leftchild;
    TeamTreeNode *rightchild;

    // constructor initializes the class with the provided team name and goals scored
    TeamTreeNode(string name, int goals)
    {
        this->teamname = name;
        this->goalsscored = goals;
        leftchild = NULL;
        rightchild = NULL;
    }
};

class TeamTree
{
public:
    TeamTreeNode *root = nullptr;
    TeamTreeNode *loc = nullptr;
    TeamTreeNode *ploc = nullptr;


    TeamTreeNode *sortedListtoBST(Team *head)
    {
        // returs zero if head is null
        if (head == NULL)
        {
            return NULL;
        }

        // if there is only one element then it creates a new tree with the data of single element
        // this is also the base case for recursion

        else if (head->next == NULL)
        {
            return new TeamTreeNode(head->team, head->goals);
        }

        // balanced binary tree logic is implemented here three pointers are used to find the middle of the list
        // all the pointers are initialized to head of dll
        else
        {
            Team *previous = head;
            Team *fast = head;
            Team *slow = head;

            // pointer named fast moves twice at a time and slow moves once
            while (fast != NULL && fast->next != NULL)
            {
                // here previous will have the current position of slow ans then slow and quick are incremented
                previous = slow;
                slow = slow->next;
                fast = fast->next->next;

                // by the fast reaches the of ll slow will be pointing to the middle element
                // slow will be pointing to middle element of ll
                // previous will be pointing to the element before the middle element
            }
            // the previous pointer is used to disconnect the dll into two halves
            previous->next = NULL;

            TeamTreeNode *root = new TeamTreeNode(slow->team, slow->goals);
            // new tree is created using the data from middle element (i.e slow)
            root->leftchild = sortedListtoBST(head);
            // recursive call from head to previous for left subtree
            root->rightchild = sortedListtoBST(slow->next);
            // recursive call from slow next which is the element after the middle till

            return root;
            // root of the subtree is returned
        }
    }

    void InOrderTrav(TeamTreeNode *temp)
    {
        if (temp != NULL)
        {
            // LNR order for traversal
            InOrderTrav(temp->leftchild);
            cout << temp->teamname << ", " << temp->goalsscored << endl;
            InOrderTrav(temp->rightchild);
        }
    }

    void SearchTeam(string name)
    {
        if (root == NULL)
        {
            cout << "The tree is empty, searching not possible" << endl;
        }

        else
        {
            loc = root;
            ploc = NULL;

            while (loc != NULL && loc->teamname != name)
            {
                if (name.compare(loc->teamname) < 0)
                {
                    ploc = loc;
                    loc = loc->leftchild;
                }

                else
                {
                    ploc = loc;
                    loc = loc->rightchild;
                }
            }
        }
    }
};