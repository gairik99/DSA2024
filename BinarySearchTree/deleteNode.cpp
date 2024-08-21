#include <bits/stdc++.h>
using namespace std;

TreeNode *deleteNode(TreeNode *root, int key)
{
    // Check if the root is empty
    if (root == NULL)
    {
        // Return null if the root is empty
        return NULL;
    }

    // If the current root node has the key to be deleted
    if (root->val == key)
    {
        // Delete the node using the helper function
        return helper(root);
    }

    // Create a dummy node pointing to the root
    TreeNode *dummy = root;
    // While loop to traverse the tree
    while (root != NULL)
    {
        // If the value to be deleted
        // is in the left subtree
        if (root->val > key)
        {
            // If the left child exists and
            // its value matches the key
            if (root->left != NULL && root->left->val == key)
            {

                // Delete the node using the helper function
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            // If the value is not in the left
            // subtree, move to the right subtree
            if (root->right != NULL && root->right->val == key)
            {
                // Delete the node using the helper function
                root->right = helper(root->right);
                break;
            }
            else
            {
                // Move to the right subtree
                root = root->right;
            }
        }
    }

    // Return the modified tree
    return dummy;
}

// Helper function to delete the node
TreeNode *helper(TreeNode *root)
{
    // If the left child of the root is null,
    // return the right child
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {

        // If the right child is null,
        // return the left child
        return root->left;
    }

    // If both left and right children exist
    // Store the right child

    TreeNode *rightChild = root->right;

    // Find the last right child of the left subtree
    TreeNode *lastRight = findLastRight(root->left);

    // Set the right child of the last
    // right node to the stored right child
    lastRight->right = rightChild;

    // Return the left child as the new subtree
    return root->left;
}

// Helper function to find the
// last right node in a subtree
TreeNode *findLastRight(TreeNode *root)
{
    // Traverse to the rightmost node in the subtree
    if (root->right == NULL)
    {
        // Return the rightmost node
        return root;
    }

    // Recursively find the last right node
    return findLastRight(root->right);
}