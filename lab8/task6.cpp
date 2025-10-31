#include <iostream>
using namespace std;

struct Node {
    int empID;
    Node* left;
    Node* right;
    Node(int id) {
        empID = id;
        left = right = nullptr;
    }
};

class EmployeeBST {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);
        if (id < node->empID)
            node->left = insert(node->left, id);
        else if (id > node->empID)
            node->right = insert(node->right, id);
        return node;
    }

    Node* findLCA(Node* node, int id1, int id2) {
        if (node == nullptr)
            return nullptr;
        if (id1 < node->empID && id2 < node->empID)
            return findLCA(node->left, id1, id2);
        if (id1 > node->empID && id2 > node->empID)
            return findLCA(node->right, id1, id2);
        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->empID << " ";
        inorder(node->right);
    }

public:
    EmployeeBST() {
        root = nullptr;
    }

    void addEmployee(int id) {
        root = insert(root, id);
    }

    void displayEmployees() {
        cout << "\nEmployee IDs (Inorder Traversal): ";
        inorder(root);
        cout << endl;
    }

    void findCommonManager(int id1, int id2) {
        Node* manager = findLCA(root, id1, id2);
        if (manager != nullptr)
            cout << "Closest common manager for Employee " << id1
                 << " and Employee " << id2 << " is Employee ID: "
                 << manager->empID << endl;
        else
            cout << "Employees not found in the hierarchy." << endl;
    }
};

int main() {
    EmployeeBST company;
    company.addEmployee(50);
    company.addEmployee(30);
    company.addEmployee(70);
    company.addEmployee(20);
    company.addEmployee(40);
    company.addEmployee(60);
    company.addEmployee(80);

    company.displayEmployees();

    int emp1, emp2;
    cout << "\nEnter first employee ID: ";
    cin >> emp1;
    cout << "Enter second employee ID: ";
    cin >> emp2;

    company.findCommonManager(emp1, emp2);
    return 0;
}
