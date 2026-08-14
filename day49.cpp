// Problem: BST Insert

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

TreeNode* insert(TreeNode* root, int key) {
    // If tree is empty, create a new node
    if (root == nullptr) {
        return new TreeNode(key);
    }

    // Insert in left subtree
    if (key < root->val) {
        root->left = insert(root->left, key);
    }
    // Insert in right subtree
    else if (key > root->val) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Inorder traversal to display BST
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    inorder(root);

    return 0;
}