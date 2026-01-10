#include <iostream>
using namespace std;

//it can function as both FIFO AND LIFO
//Imagine deque like circular queue but it doesn`t follow FIFO principal
const int MAX_SIZE = 100;

class Deque {
private:
    int arr[MAX_SIZE];
    int front, rear;
public:
    Deque() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
    }

    void insertFront(int data) {
        if (isFull()) {
            cout << "Deque is full, cannot insert at front.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        arr[front] = data;
        cout << "Inserted " << data << " at the front.\n";
    }

    void insertRear(int data) {
        if (isFull()) {
            cout << "Deque is full, cannot insert at rear.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = data;
        cout << "Inserted " << data << " at the rear.\n";
    }

    //clockwise deletion
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from front.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        cout << "Deleted element from the front.\n";
    }

    //anticlockwise deletion
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from rear.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
        cout << "Deleted element from the rear.\n";
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Deque dq;

    dq.insertFront(5);
    dq.insertRear(10);
    dq.insertFront(3);

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    dq.deleteFront();
    cout << "Front element after deletion: " << dq.getFront() << endl;

    dq.deleteRear();
    cout << "Rear element after deletion: " << dq.getRear() << endl;

    return 0;
}
