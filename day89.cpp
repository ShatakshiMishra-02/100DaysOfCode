// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Books must be allocated in contiguous order.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

// Sample Input
// 4 2
// 12 34 67 90

// Sample Output
// 113

// Explanation
// One optimal allocation is:
// Student 1: 12 + 34 + 67 = 113
// Student 2: 90
// Maximum pages = 113 (minimum possible).

#include <bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>& pages, int m, long long maxPages) {
    int students = 1;
    long long sum = 0;

    for (int page : pages) {
        if (sum + page <= maxPages) {
            sum += page;
        } else {
            students++;
            sum = page;

            if (students > m)
                return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> pages(n);
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        cin >> pages[i];

        low = max(low, (long long)pages[i]);
        high += pages[i];
    }

    // Binary search for minimum possible maximum pages
    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (canAllocate(pages, m, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << endl;

    return 0;
}