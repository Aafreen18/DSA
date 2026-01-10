#include <iostream>
#include<vector>
#include<algorithm>   // includes all standard libraries
using namespace std;

int main() {
    vector<int> arr = {5, 2, 8, 3, 7, 4, 9, 6, 1};

    sort(arr.begin(), arr.end(), [](int a, int b) {
        // both odd → descending order
        if (a % 2 != 0 && b % 2 != 0)
            return a > b;

        // both even → ascending order
        if (a % 2 == 0 && b % 2 == 0)
            return a < b;

        // odd comes before even
        return (a % 2 != 0);
    });

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
