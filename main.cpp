#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

void algorithm(Node* root, vector<int> list, int total, const int combtotal);
void printCombination(Node*);

int main()
{
    vector<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    int total = 0;
    int combtotal = 3;
    
    for (int i = 0; i < list.size(); i++)
    {
        Node* root = new Node; //Create root node for each number in the list
        root->num = list[i];
        root->parent = NULL; 
        total += root->num;

        algorithm(root, list, total, combtotal);

        total = 0;
    }
}

/*Recursive Algorithm to list all possible patterns that add to a certain sum */
void algorithm(Node* root, vector<int> list, int total, const int combtotal)
{
    for (int i = 0; i < list.size(); i++)
    {
        Node* newNode = root->createChild(list[i]); //Create the child 
        total += newNode->num;

        if (total == combtotal) //Found a combination
        {
            cout << "Combination Found" << endl;
            printCombination(newNode);
            cout << endl;
        }
        else if (total < combtotal) //Only go further if the total hasn't surpassed the actual total we want
        {
            algorithm(newNode, list, total, combtotal);
        }

        total -= newNode->num; //Subtract the amount added because new loop means new child
    }
}

//Starting from the leaf node, prints out the combination. 
void printCombination(Node* leaf)
{
    if (leaf == NULL)
    {
        return;
    }
    cout << leaf->num << " ";
    printCombination(leaf->parent);
}
