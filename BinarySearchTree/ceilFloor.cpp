#include <bits/stdc++.h>
using namespace std;

vector<int> floorCeilOfBST(TreeNode *root, int key)
{
    // your code goes here
    int floor = -1;
    int ceil = -1;

    // Find the floor value
    // Start from the root of the BST
    TreeNode *current = root;
    while (current)
    {
        // If the key matches the current node's value
        if (current->data == key)
        {
            // Set floor to this value
            floor = current->data;
            break;
            /* If the key is greater than the current node's value
               Update floor to the current node's value
               If the key is smaller than the current node's value
               Move to the left subtree to find a smaller value */
        }
        else if (current->data < key)
        {
            floor = current->data;
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    // Find the ceil value

    // Reset current to start from the root again
    current = root;
    while (current)
    {
        // If the key matches the current node's value
        if (current->data == key)
        {
            // Set ceil to this value
            ceil = current->data;
            break;

            /* If the key is smaller than the current node's value
             Update ceil to the current node's value
             If the key is greater than the current node's value
             Move to the right subtree to find a larger value */
        }
        else if (current->data > key)
        {
            ceil = current->data;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // Return the floor and ceil values as a vector
    return {floor, ceil};
}