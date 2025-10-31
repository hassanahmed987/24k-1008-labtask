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

    int countNodes(Node* node) {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(Node* node) {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
            return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int treeHeight(Node* node) {
        if (node == nullptr)
            return 0;
        int leftH = treeHeight(node->left);
        int rightH = treeHeight(node->right);
        return 1 + max(leftH, rightH);
    }

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void displayProperties() {
        cout << "Total Nodes: " << countNodes(root) << endl;
        cout << "Leaf Nodes: " << countLeaves(root) << endl;
        cout << "Height of Tree: " << treeHeight(root) << endl;
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

    tree.displayProperties();
    return 0;
}
