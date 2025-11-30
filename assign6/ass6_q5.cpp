#include<iostream>
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

bool isCircular(Node* head) {
    if (head == NULL) 
        return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
   
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->next = third;
    third->next = head; 

    if (isCircular(head))
        cout << "The linked list is Circular." << endl;
    else
        cout << "The linked list is NOT Circular." << endl;

    return 0;
}
