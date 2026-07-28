// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;

    // Push elements
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    int m;
    cin >> m;

    // Pop m elements
    while (m-- && !st.empty()) {
        st.pop();
    }

    // Print remaining elements from top to bottom
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}