#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Node.h"

using namespace std;

void algorithm(Node* root, vector<int> list, int total, const int sum);
void printCombination(Node*);

bool found = false; //Global Variable to keep track if the algorithm found a combination or not
int main()
{
    //To store the list of candidates
    vector<int> list;

    //For reading files
    ifstream infile;
    infile.open("numberselect.txt");

    string numbers;

    getline(infile, numbers); //Skip first line
    getline(infile, numbers);
    
    stringstream num(numbers);
    int value;
    while (num >> value)
    {
        if (value <= 0)
        {
            cout << "ERROR encountered: Please enter a number > 0" << endl;
            return 0;
        }
        else
        {
            list.push_back(value);
        }
    }

    getline(infile, numbers); //Skip third line
    getline(infile, numbers);

    int sum = stoi(numbers);
    if (sum <= 0)
    {
        cout << "ERROR encountered: Please enter a number > 0" << endl;
        return 0;
    }
   
    int total = 0; //Partial total to maintain as algorithm goes further down
    
    for (int i = 0; i < list.size(); i++)
    {
        Node* root = new Node; //Create root node for each number in the list
        root->num = list[i];
        root->parent = NULL; 
        total += root->num;

        if (total == sum) //Base case: sum = one of the candidates
        {
            cout << "Combination Found: " << endl;
            cout << root->num << endl;
        }

        algorithm(root, list, total, sum);

        total = 0; //Reset the total
    }

    if (!found)
    {
        cout << "NO COMBINATION FOUND :(" << endl;
    }
}

/*Recursive Algorithm to list all possible patterns that add to a certain sum */
void algorithm(Node* root, vector<int> list, int total, const int sum)
{
    for (int i = 0; i < list.size(); i++)
    {
        Node* newNode = root->createChild(list[i]); //Create the child 
        total += newNode->num;

        if (total == sum) //Found a combination
        {
            found = true;
            cout << "Combination: " << endl;
            printCombination(newNode);
            cout << endl;
        }
        else if (total < sum) //Only go further if the total hasn't surpassed the actual total we want
        {
            algorithm(newNode, list, total, sum);
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
