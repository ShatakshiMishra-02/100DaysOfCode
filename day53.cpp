// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

// Build tree from level-order input
TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i >= arr.size())
            break;

        // Right child
        if (arr[i] != -1) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    // horizontal distance -> nodes
    map<int, vector<int>> vertical;

    // node, horizontal distance
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        vertical[hd].push_back(node->val);

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Print column by column
    for (auto& column : vertical) {
        for (int value : column.second) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    TreeNode* root = buildTree(arr);

    verticalOrder(root);

    return 0;
}