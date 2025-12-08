#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingSort(vector<int>& arr, int exp) {
    int size = arr.size();

    // 1️⃣ Find the maximum element (range)
    int max_val = *max_element(arr.begin(), arr.end());

    // 2️⃣ Create count and output arrays
    vector<int> count(10, 0);
    vector<int> output(size);

    // 3️⃣ Count each element and store frequency
    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 4️⃣ Modify count[i] so it stores cumulative counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 5️⃣ Build the output array (traverse input from right → left for stability)
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--; // decrease count after placing element
    }

    // 6️⃣ Copy sorted elements back into original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void RadixSort(vector<int> &arr){
    int maxNum = *max_element(arr.begin(), arr.end());

    for(int i=1; maxNum / i > 0; i*=10){
        countingSort(arr, i);
    }
}

int main() {
    vector<int> arr = {4, 26, 2, 18, 3, 3, 100};

    RadixSort(arr);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
