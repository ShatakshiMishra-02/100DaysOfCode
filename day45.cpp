// Problem Statement:
// Find the height (maximum depth) of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print the height of the tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 -1

// Output:
// 3

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(int n) {
    if (n == 0) return NULL;

    int val;
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    int count = 1;

    while (!q.empty() && count < n) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (count < n) {
            cin >> val;
            count++;

            if (val != -1) {
                curr->left = new Node(val);
                q.push(curr->left);
            }
        }

        // Right child
        if (count < n) {
            cin >> val;
            count++;

            if (val != -1) {
                curr->right = new Node(val);
                q.push(curr->right);
            }
        }
    }

    return root;
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    queue<Node*> q;
    q.push(root);

    int h = 0;

    while (!q.empty()) {
        int size = q.size();
        h++;

        while (size--) {
            Node* curr = q.front();
            q.pop();

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }

    return h;
}

int main() {
    int N;
    cin >> N;

    Node* root = buildTree(N);

    cout << height(root) << endl;

    return 0;
}