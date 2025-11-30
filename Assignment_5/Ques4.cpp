#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) { 
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;    
        curr->next = prev;    
        prev = curr;         
        curr = next;          
    }

    return prev;  
}

int main() {
    Node* head = NULL;

    int arr[] = {1, 2, 3, 4};
    for (int x : arr) {
        insertAtEnd(head, x);
    }

    cout << "Original List: ";
    display(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}