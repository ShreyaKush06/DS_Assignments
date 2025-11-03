#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Insert node (no duplicates)
Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// Find min value node (for delete helper)
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        Node* minNode = findMin(root->right);
        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->data);
    }
    return root;
}

// Maximum depth (height)
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Minimum depth
int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder print for checking
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int val : arr) root = insert(root, val);

    cout << "Inorder before deletion: ";
    inorder(root);

    root = deleteNode(root, 10);
    cout << "\nInorder after deleting 10: ";
    inorder(root);

    cout << "\nMax Depth: " << maxDepth(root);
    cout << "\nMin Depth: " << minDepth(root);
}
