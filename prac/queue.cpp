#include <iostream>
using namespace std;

class myQueue {
public:
    int arr[1000];
    int front;
    int rear;
    int capacity;

    myQueue(int n) {
        front = -1;
        rear = -1;
        capacity = n;
    }

    bool isEmpty() {
        return (front == rear);
    }

    bool isFull() {
        return (rear == capacity - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;  // first element
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        front++;
        if (front > rear) { // queue becomes empty
            front = rear = -1;
        }
    }

    int getFront() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};
