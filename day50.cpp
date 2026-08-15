// Problem: BST Search

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    bool searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return false;

        if (root->val == val)
            return true;

        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

int main() {
    // Creating BST:
    //        4
    //       / \
    //      2   7
    //     / \
    //    1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    Solution obj;

    if (obj.searchBST(root, val))
        cout << "Value found in BST" << endl;
    else
        cout << "Value not found in BST" << endl;

    return 0;
}