// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(vector<pair<int, int>>& arr, int low, int mid, int high,
               vector<int>& ans) {

        vector<pair<int, int>> temp;

        int i = low;
        int j = mid + 1;
        int rightSmaller = 0;

        while (i <= mid && j <= high) {

            if (arr[j].first < arr[i].first) {
                // Right element is smaller
                rightSmaller++;
                temp.push_back(arr[j]);
                j++;
            }
            else {
                // All smaller right elements counted so far
                ans[arr[i].second] += rightSmaller;
                temp.push_back(arr[i]);
                i++;
            }
        }

        // Remaining left elements
        while (i <= mid) {
            ans[arr[i].second] += rightSmaller;
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining right elements
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int low, int high,
                   vector<int>& ans) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid + 1, high, ans);

        merge(arr, low, mid, high, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, 0);

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};

int main() {

    vector<int> nums = {5, 2, 6, 1};

    Solution obj;

    vector<int> ans = obj.countSmaller(nums);

    cout << "Count of smaller elements on right: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}