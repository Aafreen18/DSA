//A segment tree is a tree-based data structure that divides an array into segments and stores information about each segment, enabling efficient range queries and point updates.

//Balanced binary tree where each node represents an interval or segment of the array

#include <iostream>
#include <vector>
using namespace std;

vector<int> seg;   // segment tree
vector<int> arr;   // original array

void build(int idx, int left, int right) {
    if (left == right) {
        seg[idx] = arr[left];   // leaf node
        return;
    }

    int mid = (left + right) / 2;

    build(2 * idx + 1, left, mid);        // left child
    build(2 * idx + 2, mid + 1, right);   // right child

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2]; // merge
}

int main() {
    arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();

    seg.resize(4 * n);   // safe size

    build(0, 0, n - 1);

    return 0;
}
