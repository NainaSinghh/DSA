#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed!" << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << q1.front() << " popped!" << endl;
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed!" << endl;
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << q.front() << " popped!" << endl;
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        cout << "Top element: " << q.front() << endl;
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is EMPTY!" << endl;
            return;
        }
        queue<int> temp = q;
        cout << "Stack (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues s2;
    StackUsingOneQueue s1;
    int choice, value, type;

    cout << "Choose Stack Implementation:\n";
    cout << "1. Using Two Queues\n";
    cout << "2. Using One Queue\n";
    cout << "Enter your choice: ";
    cin >> type;

    do {
        cout << "\n=== STACK MENU ===\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            if (type == 1)
                s2.push(value);
            else
                s1.push(value);
            break;

        case 2:
            if (type == 1)
                s2.pop();
            else
                s1.pop();
            break;

        case 3:
            if (type == 1)
                s2.top();
            else
                s1.top();
            break;

        case 4:
            if (type == 1)
                s2.display();
            else
                s1.display();
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
