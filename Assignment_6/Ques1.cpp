#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    cout << "Node inserted at beginning.\n";
}

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        cout << "Node inserted as first node.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Node inserted at end.\n";
}

// Delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Node not found.\n";
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
    cout << "Node deleted.\n";
}

// Search a node
void searchNode(int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Node found!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node not found.\n";
}

// Display list
void display() {
    Node* temp = head;
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Delete Node\n4. Search Node\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> value; insertBegin(value); break;
            case 2: cout << "Enter value: "; cin >> value; insertEnd(value); break;
            case 3: cout << "Enter value to delete: "; cin >> value; deleteNode(value); break;
            case 4: cout << "Enter value to search: "; cin >> value; searchNode(value); break;
            case 5: display(); break;
            case 6: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}