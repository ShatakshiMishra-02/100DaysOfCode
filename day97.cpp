// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Sort meetings by start time
    sort(intervals.begin(), intervals.end());

    // Min-heap to store meeting end times
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto& meeting : intervals) {
        int start = meeting[0];
        int end = meeting[1];

        // Free rooms where meetings have ended
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        // Allocate a room for the current meeting
        pq.push(end);
    }

    // Maximum rooms needed
    return pq.size();
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> intervals(n);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals[i] = {start, end};
    }

    cout << minMeetingRooms(intervals) << endl;

    return 0;
}