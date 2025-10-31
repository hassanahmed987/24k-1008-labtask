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

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    bool isFull(Node* node) {
        if (node == nullptr)
            return true;
        if ((node->left == nullptr && node->right != nullptr) ||
            (node->left != nullptr && node->right == nullptr))
            return false;
        return isFull(node->left) && isFull(node->right);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void checkFullBinaryTree() {
        if (isFull(root))
            cout << "The tree is a full binary tree." << endl;
        else
            cout << "The tree is not a full binary tree." << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.checkFullBinaryTree();
    return 0;
}
