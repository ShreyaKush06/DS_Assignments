#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

int sizeDLL(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct NodeC {
    int data;
    NodeC* next;
};

int sizeCLL(NodeC* head) {
    if (!head) return 0;
    int count = 0;
    NodeC* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    // Example for DLL
    Node* n1 = new Node{10, NULL, NULL};
    Node* n2 = new Node{20, NULL, n1};
    n1->next = n2;
    cout << "Size of DLL: " << sizeDLL(n1) << endl;

    // Example for CLL
    NodeC* a = new NodeC{5, NULL};
    NodeC* b = new NodeC{10, NULL};
    NodeC* c = new NodeC{15, NULL};
    a->next = b; b->next = c; c->next = a;
    cout << "Size of CLL: " << sizeCLL(a) << endl;
}