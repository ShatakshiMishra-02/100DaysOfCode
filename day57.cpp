// Problem Statement:
// Convert a binary tree into its mirror image by swapping left and right children at every node.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print inorder traversal of mirrored tree

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 7 3 6 1 5 2 4

// Explanation:
// Each node’s left and right children are swapped recursively.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Create tree from level-order traversal
TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

// Convert tree into mirror image
void mirror(TreeNode* root) {
    if (root == nullptr)
        return;

    // Swap left and right children
    swap(root->left, root->right);

    // Recursively mirror both subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    TreeNode* root = buildTree(arr);

    // Convert to mirror tree
    mirror(root);

    // Print inorder traversal
    inorder(root);

    return 0;
}