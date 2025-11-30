#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next, *prev;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* left = head;
    Node* right = head;
    while (right->next) right = right->next;
    while (left && right && left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* a = new Node{'r', NULL, NULL};
    Node* b = new Node{'a', NULL, a};
    Node* c = new Node{'d', NULL, b};
    Node* d = new Node{'a', NULL, c};
    Node* e = new Node{'r', NULL, d};
    a->next = b; b->next = c; c->next = d; d->next = e;

    cout << (isPalindrome(a) ? "True" : "False") << endl;
    return 0;
}