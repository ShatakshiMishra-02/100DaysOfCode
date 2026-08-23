// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.

#include <bits/stdc++.h>
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
    int preIndex = 0;
    unordered_map<int, int> inMap;

    TreeNode* buildTree(vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        // First element of preorder is the root
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int rootIndex = inMap[rootValue];

        // Build left subtree
        root->left = buildTree(preorder, inStart, rootIndex - 1);

        // Build right subtree
        root->right = buildTree(preorder, rootIndex + 1, inEnd);

        return root;
    }

    void postorder(TreeNode* root) {
        if (root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> preorder(N);
    vector<int> inorder(N);

    for (int i = 0; i < N; i++)
        cin >> preorder[i];

    for (int i = 0; i < N; i++)
        cin >> inorder[i];

    Solution sol;

    // Store positions of elements in inorder
    for (int i = 0; i < N; i++)
        sol.inMap[inorder[i]] = i;

    TreeNode* root = sol.buildTree(preorder, 0, N - 1);

    // Print postorder
    sol.postorder(root);

    return 0;
}