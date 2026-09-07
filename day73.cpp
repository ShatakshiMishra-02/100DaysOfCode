// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

// Explanation
// The character 'f' occurs only once in the string and appears before any other non-repeating character.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[26] = {0};

    // Count frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find the first non-repeating character
    for (char c : s) {
        if (freq[c - 'a'] == 1) {
            cout << c;
            return 0;
        }
    }

    // If no non-repeating character exists
    cout << '$';

    return 0;
}
