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

void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    cout << val << " Inserted at the beginning.\n";
}

void insertAtEnd(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    cout << val << " Inserted at the end.\n";
}

void insertBefore(Node* &head, int key, int val) {
    if (head == NULL) { cout << "List is empty!\n"; return; }

    if (head->data == key) {
        insertAtBeginning(head, val);
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;

    if (temp->next == NULL) {
        cout << "Key not found!\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << val << " Inserted before " << key << ".\n";
}

void insertAfter(Node* &head, int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;

    if (temp == NULL) {
        cout << "Key not found!\n";
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    cout << val << " Inserted after " << key << ".\n";
}

void deleteFromBeginning(Node* &head) {
    if (head == NULL) { cout << "List is empty!\n"; return; }
    Node* temp = head;
    head = head->next;
    cout << temp->data << " Deleted from beginning.\n";
    delete temp;
}

void deleteFromEnd(Node* &head) {
    if (head == NULL) { cout << "List is empty!\n"; return; }

    if (head->next == NULL) {
        cout << head->data << " Deleted from end.\n";
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;

    cout << temp->next->data << " Deleted from end.\n";
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(Node* &head, int key) {
    if (head == NULL) { cout << "List is empty!\n"; return; }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        cout << key << " Deleted.\n";
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;

    if (temp->next == NULL) {
        cout << "Key not found!\n";
        return;
    }

    Node* toDelete = temp->next;
    cout << key << " Deleted.\n";
    temp->next = temp->next->next;
    delete toDelete;
}

void search(Node* head, int key) {
    int pos = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout << key << " Found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << key << " Not found in the list.\n";
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int choice, val, key;

    do {
        cout << "\nMENU\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert before key\n";
        cout << "4. Insert after key\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search node\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; insertAtBeginning(head, val); break;
            case 2: cout << "Enter value: "; cin >> val; insertAtEnd(head, val); break;
            case 3: cout << "Enter key & value: "; cin >> key >> val; insertBefore(head, key, val); break;
            case 4: cout << "Enter key & value: "; cin >> key >> val; insertAfter(head, key, val); break;
            case 5: deleteFromBeginning(head); break;
            case 6: deleteFromEnd(head); break;
            case 7: cout << "Enter key: "; cin >> key; deleteSpecific(head, key); break;
            case 8: cout << "Enter key: "; cin >> key; search(head, key); break;
            case 9: display(head); break;
            case 0: cout << "Exiting program\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}