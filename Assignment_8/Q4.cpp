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

// Helper function using pointer bounds instead of INT_MIN / INT_MAX
bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
    if (root == nullptr)
        return true;

    // If this node violates the min/max constraint
    if (minNode != nullptr && root->data <= minNode->data)
        return false;
    if (maxNode != nullptr && root->data >= maxNode->data)
        return false;

    // Recur for left and right subtrees
    return isBSTUtil(root->left, minNode, root) &&
           isBSTUtil(root->right, root, maxNode);
}

bool isBST(Node* root) {
    return isBSTUtil(root, nullptr, nullptr);
}

int main() {
    // ✅ Example of a valid BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    if (isBST(root))
        cout << "The tree is a BST";
    else
        cout << "The tree is NOT a BST";

    return 0;
}
