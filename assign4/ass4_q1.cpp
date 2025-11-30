#include <iostream>
using namespace std;
#define SIZE 5
class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
        cout << value << " enqueued successfully!" << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully!" << endl;
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;
    do {
        cout << "\n=== QUEUE MENU ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is EMPTY!" << endl;
            else
                cout << "Queue is NOT empty." << endl;
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is FULL!" << endl;
            else
                cout << "Queue is NOT full." << endl;
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
