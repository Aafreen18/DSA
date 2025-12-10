#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int size = arr.size();

    // 1️⃣ Find the maximum element (range)
    int max_val = *max_element(arr.begin(), arr.end());

    // 2️⃣ Create count and output arrays
    vector<int> count(max_val + 1, 0);
    vector<int> output(size);

    // 3️⃣ Count each element and store frequency
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // 4️⃣ Modify count[i] so it stores cumulative counts
    for (int i = 1; i <= max_val; i++) {
        count[i] += count[i - 1];
    }

    // 5️⃣ Build the output array (traverse input from right → left for stability)
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--; // decrease count after placing element
    }

    // 6️⃣ Copy sorted elements back into original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 13, 3, 1};

    countingSort(arr);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
