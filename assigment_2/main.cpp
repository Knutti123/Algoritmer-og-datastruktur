#include <iostream>
#include <vector>
#include <math.h>
#include "BinarySearchTree.h"

using namespace std;

// task 1
string Task1(string s)
{
    string placeholder = "";
    vector<string> v;
    int highest = 0;
    int size = s.size();
    for (size_t i = 0; i < size; i++)
    {
        s[i] = tolower(s[i]);
    }
    for (size_t i = 0; i < size; i++)
    {
        if (s[i] == ' ' or s[i] == ',' or s[i] == '.')
        {
            v.push_back(placeholder);
            placeholder = "";
        }
        else
        {
            placeholder += s[i];
        }
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        int counter = 0;
        for (size_t j = 0; j < v.size(); j++)
        {
            if (v[i] == v[j] and v[i] != "")
            {
                counter++;
                if (counter > highest)
                {
                    highest = counter;
                    placeholder = v[i];
                }
            }
        }
    }
    return placeholder;
}

// task 2
BinarySearchTree tree_create()
{
    BinarySearchTree tree;
    // Leftmost branch goes 4 levels deep
    // tree.insert(10);   // Root
    // tree.insert(5);    // Level 2, left of 10
    // tree.insert(3);    // Level 3, left of 5
    // tree.insert(1);    // Level 4, left of 3
    
    // // Right branch goes only 2 levels deep
    // tree.insert(15);   // Level 2, right of 10
    // tree.insert(17);   // Level 3, right of 15

    tree.insert(7);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    tree.insert(28);
    tree.insert(55);
    tree.insert(51);
    tree.insert(48);
    tree.insert(40);
    tree.insert(35);
    tree.insert(60);
    tree.insert(58);
    tree.insert(57);
    tree.insert(69);
    return tree;
}


int main()
{
    // string s = "The cattle were running back and forth, but there was no wolf to be seen, heard, or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";
    // cout << Task1(s) << endl;
    BinarySearchTree tree = tree_create();
    tree.identifyBranches();
    cout<<tree.identifyBranches()<<endl;
    
}