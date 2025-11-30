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
    void findMiddle() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
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
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insertAtEnd(val);
    }
    list.display();
    list.findMiddle();
    return 0;
}
