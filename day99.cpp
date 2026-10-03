// Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
// Sort cars by position in descending order and calculate time to reach target.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // Sort by position in descending order
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0.0;

        for (auto car : cars) {
            int pos = car.first;
            int spd = car.second;

            double time = (double)(target - pos) / spd;

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};

int main() {
    Solution obj;

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    cout << obj.carFleet(target, position, speed) << endl;

    return 0;
}