#include <iostream>
using namespace std;

//It is used to sort an array in ascending order
void heapify(int arr[], int n, int i){
    int smallest = i;
    int leftIdx = 2*i + 1;
    int rightIdx = 2*i + 2;

    if(leftIdx < n && arr[smallest] > arr[leftIdx]){
        smallest = leftIdx;
    }
    
    if(rightIdx < n && arr[smallest] > arr[rightIdx]){
        smallest = rightIdx;
    }
    
    if(smallest != i){
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n){
    // 1. Build min heap
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);//heapify(5, 1)
    }

    int len = n;
    // 2. Extract elements from heap one by one
    while(len > 1){
        swap(arr[0], arr[len-1]);  // swap min with last element
        len--;
        heapify(arr, len, 0);      // restore min heap
    }
}

int main(){
    int arr[] = {5,7,4,1,3, 2,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
