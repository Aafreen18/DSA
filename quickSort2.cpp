#include <iostream>
#include <vector>
using namespace std;

// Function to perform quicksort
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return ;
    }

    int s = low;
    int e = high;

    int m = s+(e-s)/2;
    int pivot = arr[m];

    while(s <= e){

        while(arr[s] < pivot){
            s++;
        }

        while(arr[e] > pivot){
            e--;
        }

        if(s <= e){
            arr[s] = arr[s]^arr[e];
            arr[e] = arr[s]^arr[e];
            arr[s] = arr[s]^arr[e];

            s++;
            e--;
        }
    }

    quickSort(arr, low, e);
    quickSort(arr, s, high);
}

int main() {
    vector<int> arr = {12, 7, 11, 8, 5, 6, 3};
    int n = arr.size();
    
    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, n - 1);
    
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
