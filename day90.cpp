// Problem Statement
// Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

// Determine the minimum time required to paint all boards.

// Input Format
// n k
// n space-separated integers representing board lengths

// Output Format
// Print the minimum time required to paint all boards.

// Sample Input
// 4 2
// 10 20 30 40

// Sample Output
// 60

// Explanation
// One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.

#include <bits/stdc++.h>
using namespace std;

bool canPaint(vector<int>& boards, int k, long long maxTime) {
    int painters = 1;
    long long time = 0;

    for (int board : boards) {
        if (time + board <= maxTime) {
            time += board;
        } else {
            painters++;
            time = board;

            if (painters > k)
                return false;
        }
    }

    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boards(n);
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> boards[i];
        low = max(low, (long long)boards[i]);
        high += boards[i];
    }

    // Binary search for minimum possible maximum time
    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, k, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << endl;

    return 0;
}