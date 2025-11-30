#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Display CLL
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Circular Linked List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // repeat head at end
}

int main() {
    insertEnd(20);
    insertEnd(100);
    insertEnd(40);
    insertEnd(80);
    insertEnd(60);
    display();
    return 0;
}