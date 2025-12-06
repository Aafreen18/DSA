#include <iostream>
#include <string>
#include<queue>
#include <vector>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size = 0;

    Heap(){
        arr[0] = 0;
        size = 0; 
    }

    void insertVal(int val){
        
        int idx = size;
        arr[idx] = val;

        size++;

        while(idx > 0){
            int parentIdx = (idx - 1)/2;

            if(arr[parentIdx] < arr[idx]){
                swap(arr[parentIdx], arr[idx]);
                idx = parentIdx;
            }
            else{
                return;
            }
        }

        
    }

    void printHeap(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteRootNode(){
        if(size == 0){
            cout<<"Nothing to delete";
        }

        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while(i < size){
            int leftIdx = 2*i + 1;
            int rightIdx = 2*i + 2;

            if(leftIdx < size && arr[i] < arr[leftIdx]){
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }
            else if(rightIdx < size && arr[i] < arr[rightIdx]){
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }
            else{
                return ;
            }
        }
    }

    //descending
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
        int len = n;

        while(len > 1){
            //swap
            swap(arr[0], arr[len]);
            len--;

            //build max heap 
            heapify(arr, len, 0);
        }
    }
};

int main(){
    Heap h;
    // h.insertVal(60);
    // h.insertVal(50);
    // h.insertVal(40);
    // h.insertVal(30);
    // h.insertVal(20);
    // h.insertVal(55);
    // h.insertVal(70);

    // h.deleteRootNode();
    // h.printHeap();

    int arr[5] = {54, 53, 55, 52, 50};

    int n = 5;
    for(int i=n/2; i>=0; i--){
        h.heapify(arr, n, i);
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // //heapSort
    // h.heapSort(arr, n);
    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    // //maxHeap(descending)
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(5);
    // pq.push(3);
    // pq.push(6);

    // cout<<"top element "<<pq.top()<<endl;
    // pq.pop();
    // cout<<"top element "<<pq.top()<<endl;

    //minheap(ascending)
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(4);
    pq2.push(5);
    pq2.push(3);
    pq2.push(6);

    cout<<"top element "<<pq2.top()<<endl;
    pq2.pop();
    cout<<"top element "<<pq2.top()<<endl;

    return 0;
}