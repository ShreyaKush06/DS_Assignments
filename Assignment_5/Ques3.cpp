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

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr) {
        insertAtEnd(head, x);
    }

    cout << "Linked List: ";
    display(head);

    cout << "Middle element = " << findMiddle(head) << endl;

    return 0;
}