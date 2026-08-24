// Problem Statement:
// Construct a binary tree from given inorder and postorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains inorder traversal
// - Third line contains postorder traversal

// Output Format:
// - Print preorder traversal of constructed tree

// Example:
// Input:
// 5
// 4 2 5 1 3
// 4 5 2 3 1

// Output:
// 1 2 4 5 3

// Explanation:
// Postorder gives root at end, inorder divides left and right subtrees.

#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> inorderIndex;
    int postIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,
                        int left, int right) {
        if (left > right)
            return nullptr;

        // Last element of postorder is the root
        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int mid = inorderIndex[rootValue];

        // Build right subtree first because postorder is processed backwards
        root->right = buildTree(inorder, postorder, mid + 1, right);
        root->left = buildTree(inorder, postorder, left, mid - 1);

        return root;
    }

    void preorder(TreeNode* root) {
        if (root == nullptr)
            return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void solve(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        // Store position of each value in inorder
        for (int i = 0; i < n; i++)
            inorderIndex[inorder[i]] = i;

        postIndex = n - 1;

        TreeNode* root = buildTree(inorder, postorder, 0, n - 1);

        // Print preorder traversal
        preorder(root);
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> inorder(N);
    vector<int> postorder(N);

    for (int i = 0; i < N; i++)
        cin >> inorder[i];

    for (int i = 0; i < N; i++)
        cin >> postorder[i];

    Solution obj;
    obj.solve(inorder, postorder);

    return 0;
}