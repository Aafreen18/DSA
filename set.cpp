#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> uset;

    // Insert elements
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(20);
    uset.insert(20); // Duplicate, will be ignored

    // Display elements
    std::cout << "Elements in the unordered_set:\n";
    for (int elem : uset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    if (uset.find(20) != uset.end()) {
        std::cout << "20 is found in the unordered_set\n";
    } else {
        std::cout << "20 is not found in the unordered_set\n";
    }

    // Erase an element
    uset.erase(10);
    std::cout << "After erasing 10:\n";
    for (int elem : uset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
