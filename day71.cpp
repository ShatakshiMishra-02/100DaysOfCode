// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, q;
    cin >> m;
    cin >> q;

    vector<int> table(m, -1);

    for (int x = 0; x < q; x++) {
        string operation;
        int key;

        cin >> operation >> key;

        int h = key % m;

        if (operation == "INSERT") {
            // Quadratic probing
            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (table[index] == -1) {
                    table[index] = key;
                    break;
                }
            }
        }
        else if (operation == "SEARCH") {
            bool found = false;

            // Quadratic probing
            for (int i = 0; i < m; i++) {
                int index = (h + i * i) % m;

                if (table[index] == key) {
                    found = true;
                    break;
                }

                // If empty slot is reached, key cannot be present
                if (table[index] == -1) {
                    break;
                }
            }

            if (found)
                cout << "FOUND" << endl;
            else
                cout << "NOT FOUND" << endl;
        }
    }

    return 0;
}