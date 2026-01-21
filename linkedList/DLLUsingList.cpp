#include<iostream>
using namespace std;
#include<list>

int main() {
    list<int> dll;   // This is a Doubly Linked List

    // Insert elements
    dll.push_back(10);      // [10]
    dll.push_back(20);      // [10, 20]
    dll.push_front(5);      // [5, 10, 20]

    cout << "After insertions: ";
    for(int x : dll) cout << x << " ";
    cout << endl;

    // Delete elements
    dll.pop_front();        // remove 5
    dll.pop_back();         // remove 20

    cout << "After deletions: ";
    for(int x : dll) cout << x << " ";
    cout << endl;

    // Insert in middle using iterator
    auto it = dll.begin();
    ++it;                   // move to second position
    dll.insert(it, 15);     // insert before 10

    cout << "After middle insert: ";
    for(int x : dll) cout << x << " ";
    cout << endl;

    // Erase using iterator (O(1))
    it = dll.begin();
    ++it;                   // points to 10
    dll.erase(it);          // remove 10

    cout << "After erase by iterator: ";
    for(int x : dll) cout << x << " ";
    cout << endl;

    // Traverse forward
    cout << "Forward traversal: ";
    for(auto it = dll.begin(); it != dll.end(); ++it)
        cout << *it << " ";
    cout << endl;

    // Traverse backward
    cout << "Backward traversal: ";
    for(auto it = dll.rbegin(); it != dll.rend(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
