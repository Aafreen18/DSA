#include <iostream>
using namespace std;

//It is used to sort an array in descending order
void heapify(int arr[], int n, int i){
    int largest = i;
    int leftIdx = 2*i + 1;
    int rightIdx = 2*i + 2;

    if(leftIdx < n && arr[largest] < arr[leftIdx]){
        largest = leftIdx;
    }
    
    if(rightIdx < n && arr[largest] < arr[rightIdx]){
        largest = rightIdx;
    }
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    // 1. Build max heap
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);//heapify(5, 1)
    }

    int len = n;
    // 2. Extract elements from heap one by one
    while(len > 1){
        swap(arr[0], arr[len-1]);  // swap max with last element
        len--;
        heapify(arr, len, 0);      // restore max heap
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
