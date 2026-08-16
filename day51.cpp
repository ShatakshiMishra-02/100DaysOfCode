// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6

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

// Insert a node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    if (root == nullptr)
        return nullptr;

    // Both nodes are in the left subtree
    if (n1 < root->val && n2 < root->val)
        return findLCA(root->left, n1, n2);

    // Both nodes are in the right subtree
    if (n1 > root->val && n2 > root->val)
        return findLCA(root->right, n1, n2);

    // Current node is the LCA
    return root;
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int n1, n2;
    cin >> n1 >> n2;

    TreeNode* lca = findLCA(root, n1, n2);

    if (lca != nullptr)
        cout << lca->val << endl;

    return 0;
}