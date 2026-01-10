#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

int main() {
    unordered_set<int> uset;

    // Insert elements
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(20);
    uset.insert(20); // Duplicate, will be ignored

    // Display elements
    cout << "Elements in the unordered_set:\n";
    for (int elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element exists
    if (uset.find(20) != uset.end()) {
        cout << "20 is found in the unordered_set\n";
    } else {
        cout << "20 is not found in the unordered_set\n";
    }

    // Erase an element
    uset.erase(10);
    cout << "After erasing 10:\n";
    for (int elem : uset) {
        cout << elem << " ";
    }
    cout << std::endl;

    //ordered set
    set<int> oset;
    oset.insert(30);
    oset.insert(10);
    oset.insert(20);

    cout << "Elements in the ordered set:\n";
    for (int elem : oset) {
        cout << elem << " ";
    }   
    cout << endl;

    //2d set
    set<pair<int,int>> s;

    s.insert({2, 8});
    s.insert({1, 5});
    s.insert({2, 3});
    s.insert({4, 1});

    for (auto p : s) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
