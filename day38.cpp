// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(10);
    dq.push_front(5);

    cout << "Deque: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Front and Back
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    // Pop operations
    dq.pop_front();
    dq.pop_back();

    cout << "After pop_front and pop_back: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Size and Empty
    cout << "Size: " << dq.size() << endl;
    cout << "Is Empty: " << (dq.empty() ? "Yes" : "No") << endl;

    // Emplace operations
    dq.emplace_front(1);
    dq.emplace_back(100);

    cout << "After emplace: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Resize
    dq.resize(6, 50);

    cout << "After resize: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Assign
    dq.assign({7, 8, 9, 10});

    cout << "After assign: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Reverse
    reverse(dq.begin(), dq.end());

    cout << "After reverse: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Sort
    sort(dq.begin(), dq.end());

    cout << "After sort: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Erase second element
    if (dq.size() > 1)
        dq.erase(dq.begin() + 1);

    cout << "After erase: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Swap
    deque<int> dq2 = {100, 200, 300};
    dq.swap(dq2);

    cout << "After swap, dq: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // Clear
    dq.clear();

    cout << "After clear, Is Empty: " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}