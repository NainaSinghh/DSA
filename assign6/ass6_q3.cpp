#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    int getSize() {
        int count = 0;
        DNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    CNode* last;
public:
    CircularLinkedList() { last = NULL; }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (last == NULL) {
            last = newNode;
            last->next = last;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    int getSize() {
        if (last == NULL)
            return 0;
        int count = 0;
        CNode* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        CNode* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int n, val;

    cout << "Enter number of elements for Doubly Linked List: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        dll.insertAtEnd(val);
    }
    cout << "Doubly Linked List: ";
    dll.display();
    cout << "Size of Doubly Linked List = " << dll.getSize() << endl;

    cout << "\nEnter number of elements for Circular Linked List: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        cll.insertAtEnd(val);
    }
    cout << "Circular Linked List: ";
    cll.display();
    cout << "Size of Circular Linked List = " << cll.getSize() << endl;

    return 0;
}
