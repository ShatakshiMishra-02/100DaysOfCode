// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int left = 0, right = s.length() - 1;
    bool palindrome = true;

    while (left < right) {
        if (s[left] != s[right]) {
            palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (palindrome)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}