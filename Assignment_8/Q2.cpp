#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// (a) Search (Recursive)
bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search (Non-Recursive)
bool searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

// (b) Maximum element in BST
int findMax(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->right != nullptr)
        root = root->right;
    return root->data;
}

// (c) Minimum element in BST
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

// (d) Inorder Successor (Next greater node)
Node* inorderSuccessor(Node* root, Node* node) {
    Node* succ = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}

// (e) Inorder Predecessor (Next smaller node)
Node* inorderPredecessor(Node* root, Node* node) {
    Node* pred = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}

int main() {
    // Manually constructing a BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    cout << "Maximum element: " << findMax(root) << endl;
    cout << "Minimum element: " << findMin(root) << endl;

    int key = 15;
    cout << "Search Recursive (" << key << "): ";
    if (searchRecursive(root, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Search Iterative (" << key << "): ";
    if (searchIterative(root, key))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    Node* node = root->left; // node = 10
    Node* succ = inorderSuccessor(root, node);
    Node* pred = inorderPredecessor(root, node);

    if (succ != nullptr)
        cout << "Inorder Successor of " << node->data << ": " << succ->data << endl;
    else
        cout << "Inorder Successor of " << node->data << ": None" << endl;

    if (pred != nullptr)
        cout << "Inorder Predecessor of " << node->data << ": " << pred->data << endl;
    else
        cout << "Inorder Predecessor of " << node->data << ": None" << endl;

    return 0;
}

