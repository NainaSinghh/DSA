#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* last;

public:
    CircularLinkedList() {
        last = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (last == NULL) {
            last = newNode;
            last->next = last;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = last->next; 
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << last->next->data << endl; 
    }
};

int main() {
    CircularLinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Output: ";
    list.display();

    return 0;
}
