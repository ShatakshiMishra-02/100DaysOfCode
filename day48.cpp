// Problem: Count Leaf Nodes

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications 

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

int countLeafNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;

    // Leaf node: no left and right child
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (a[0] == -1) {
        cout << 0;
        return 0;
    }

    TreeNode* root = new TreeNode(a[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < n) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < n && a[i] != -1) {
            curr->left = new TreeNode(a[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && a[i] != -1) {
            curr->right = new TreeNode(a[i]);
            q.push(curr->right);
        }
        i++;
    }

    cout << countLeafNodes(root);

    return 0;
}