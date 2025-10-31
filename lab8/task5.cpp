#include <iostream>
using namespace std;

struct Node {
    int productID;
    int quantity;
    Node* left;
    Node* right;
    Node(int id, int q) {
        productID = id;
        quantity = q;
        left = right = nullptr;
    }
};

class ProductBST {
private:
    Node* root;

    Node* insert(Node* node, int id, int q) {
        if (node == nullptr)
            return new Node(id, q);
        if (id < node->productID)
            node->left = insert(node->left, id, q);
        else if (id > node->productID)
            node->right = insert(node->right, id, q);
        else
            node->quantity += q;  
        return node;
    }

    Node* search(Node* node, int id) {
        if (node == nullptr || node->productID == id)
            return node;
        if (id < node->productID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    void findMaxQuantity(Node* node, Node*& maxNode) {
        if (node == nullptr)
            return;
        if (maxNode == nullptr || node->quantity > maxNode->quantity)
            maxNode = node;
        findMaxQuantity(node->left, maxNode);
        findMaxQuantity(node->right, maxNode);
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << "Product ID: " << node->productID << " | Quantity: " << node->quantity << endl;
        inorder(node->right);
    }

public:
    ProductBST() {
        root = nullptr;
    }

    void addProduct(int id, int q) {
        root = insert(root, id, q);
    }

    void searchProduct(int id) {
        Node* res = search(root, id);
        if (res == nullptr)
            cout << "Product ID " << id << " not found." << endl;
        else
            cout << "Product ID: " << res->productID << " | Quantity: " << res->quantity << endl;
    }

    void displayAll() {
        cout << "\nCurrent Inventory:\n";
        inorder(root);
    }

    void highestStock() {
        Node* maxNode = nullptr;
        findMaxQuantity(root, maxNode);
        if (maxNode != nullptr)
            cout << "\nProduct with highest stock:\nProduct ID: " 
                 << maxNode->productID << " | Quantity: " << maxNode->quantity << endl;
    }
};

int main() {
    ProductBST store;
    store.addProduct(50, 100);
    store.addProduct(30, 75);
    store.addProduct(70, 120);
    store.addProduct(20, 50);
    store.addProduct(40, 80);
    store.addProduct(70, 30);  

    store.displayAll();

    cout << "\nEnter product ID to search: ";
    int id;
    cin >> id;
    store.searchProduct(id);

    store.highestStock();
    return 0;
}
