#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size + 1; 
        arr = new int[capacity];
        front = rear = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % capacity;
        cout << "Enqueued: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return -1; 
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        cout << "Dequeued: " << value << endl;
        return value;
    }

    void display() {
        int i = front;
        cout << "Queue: ";
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
// some examples : 
int main() {
    CircularQueue cq(5);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cq.display();
    return 0;
}
