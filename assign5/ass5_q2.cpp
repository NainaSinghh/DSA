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

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    int countAndDeleteKey(int key) {
        int count = 0;
        // Delete key at the beginning if present
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        // Delete other occurrences
        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data == key) {
                Node* del = curr->next;
                curr->next = curr->next->next;
                delete del;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "Original Linked List: ";
    list.display();

    int count = list.countAndDeleteKey(key);

    cout << "Count of " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
