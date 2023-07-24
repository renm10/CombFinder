#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

void printCombination(Node*);

int main()
{
    vector<int> list;
    list.push_back(1);
    list.push_back(9);
    list.push_back(3);
    // list.push_back(4);

    int total;
    int combtotal = 10;
    bool found = false;
    
    for (int i = 0; i < list.size(); i++)
    {
        Node* tail; // Keeps track of the tail
        Node* root = new Node;
        root->num = list[i];
        root->parent = NULL;
        tail = root;
        total = 0;
        total += root->num;
        cout << total << endl;

        while (!found)
        {
            for (int j = 0; j < list.size(); j++)
            {
                Node* newnode = new Node;
                newnode->num = list[j];
                newnode->parent = tail;
                tail = newnode;
                if (total == combtotal)
                {
                    found = true;
                    cout << "Combination Found for:"  << list[i] << endl;
                    printCombination(tail);
                }
                
                total += newnode->num;
                cout << total << endl;

                if (total > combtotal)
                {
                    //cout << "BREAK" << endl;
                    break;
                }
            }
        }
        found = false;
    }
}

void printCombination(Node* leaf)
{
    if (leaf == NULL)
    {
        return;
    }
    cout << leaf->num << " ";
    printCombination(leaf->parent);
}
