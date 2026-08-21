// Problem Statement:
// Check whether a given binary tree is symmetric around its center.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print YES if symmetric, otherwise NO

// Example:
// Input:
// 7
// 1 2 2 3 4 4 3

// Output:
// YES

// Explanation:
// Left subtree is a mirror image of the right subtree.

#include <iostream>
#include <vector>
#include <queue>
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

// Check whether two subtrees are mirror images
bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr)
        return true;

    if (left == nullptr || right == nullptr)
        return false;

    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Check symmetry of the tree
bool isSymmetric(TreeNode* root) {
    if (root == nullptr)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << "YES";
        return 0;
    }

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    if (arr[0] == -1) {
        cout << "YES";
        return 0;
    }

    // Build tree from level-order traversal
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < N) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < N && arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < N && arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    if (isSymmetric(root))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}