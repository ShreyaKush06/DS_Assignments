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

int deleteOccurrences(Node* &head, int key) {
    int count = 0;

    while (head != NULL && head->data == key) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        count++;
    }

    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            count++;
        } else {
            temp = temp->next;
        }
    }

    return count;
}

int main() {
    Node* head = NULL;

    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int x : arr) {
        insertAtEnd(head, x);
    }

    cout << "Original List: ";
    display(head);

    int key = 1;
    int count = deleteOccurrences(head, key);

    cout << "Occurrences of " << key << " = " << count << endl;
    cout << "Updated List: ";
    display(head);

    return 0;
}