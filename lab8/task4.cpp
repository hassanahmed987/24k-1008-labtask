#include <iostream>
#include <queue>
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
    bool found;

    Node* buildCompleteTree(int arr[], int n, int i) {
        if (i >= n)
            return nullptr;
        Node* node = new Node(arr[i]);
        node->left = buildCompleteTree(arr, n, 2 * i + 1);
        node->right = buildCompleteTree(arr, n, 2 * i + 2);
        return node;
    }

    int subtreeSum(Node* node, int target) {
        if (node == nullptr)
            return 0;
        int sumLeft = subtreeSum(node->left, target);
        int sumRight = subtreeSum(node->right, target);
        int total = node->data + sumLeft + sumRight;
        if (total == target && !found) {
            found = true;
            cout << "Subtree found with sum " << target << ":\n";
            display(node);
            cout << endl;
        }
        return total;
    }

    void display(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        display(node->left);
        display(node->right);
    }

public:
    BinaryTree() {
        root = nullptr;
        found = false;
    }

    void build(int arr[], int n) {
        root = buildCompleteTree(arr, n, 0);
    }

    void findSubtreeWithSum(int target) {
        subtreeSum(root, target);
        if (!found)
            cout << "No subtree found with sum " << target << "." << endl;
    }
};

int main() {
    int items[] = {10, 5, 15, 3, 7, 12, 18};
    int n = sizeof(items) / sizeof(items[0]);

    BinaryTree tree;
    tree.build(items, n);

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    tree.findSubtreeWithSum(target);
    return 0;
}
