// Problem: Height of Binary Tree

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications

#include <iostream>
#include <queue>
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

int height(TreeNode* root) {
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    int x;
    cin >> x;

    TreeNode* root = new TreeNode(x);
    queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < N; i++) {
        cin >> x;

        TreeNode* current = q.front();
        q.pop();

        if (x != -1) {
            current->left = new TreeNode(x);
            q.push(current->left);
        }

        if (i + 1 < N) {
            cin >> x;
            i++;

            if (x != -1) {
                current->right = new TreeNode(x);
                q.push(current->right);
            }
        }
    }

    cout << height(root);

    return 0;
}