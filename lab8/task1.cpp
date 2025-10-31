#include <iostream>
#include <string>
using namespace std;

struct TourPackage {
    string name;
    TourPackage* left;
    TourPackage* right;
    TourPackage(string n) {
        name = n;
        left = right = nullptr;
    }
};

class TourTree {
private:
    TourPackage* root;

    void displayTree(TourPackage* node, int level) {
        if (node == nullptr)
            return;
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "|-- " << node->name << endl;
        displayTree(node->left, level + 1);
        displayTree(node->right, level + 1);
    }

public:
    TourTree() {
        root = nullptr;
    }

    void createRoot(string name) {
        if (root == nullptr)
            root = new TourPackage(name);
        else
            cout << "Root already exists!" << endl;
    }

    void addSubPackage(string parentName, string leftName, string rightName) {
        TourPackage* parent = search(root, parentName);
        if (parent == nullptr) {
            cout << "Parent package not found!" << endl;
            return;
        }
        if (!leftName.empty() && parent->left == nullptr)
            parent->left = new TourPackage(leftName);
        if (!rightName.empty() && parent->right == nullptr)
            parent->right = new TourPackage(rightName);
    }

    TourPackage* search(TourPackage* node, string name) {
        if (node == nullptr)
            return nullptr;
        if (node->name == name)
            return node;
        TourPackage* found = search(node->left, name);
        if (found == nullptr)
            found = search(node->right, name);
        return found;
    }

    void display() {
        if (root == nullptr) {
            cout << "No tour packages added yet!" << endl;
            return;
        }
        cout << "Tour Package Hierarchy:\n";
        displayTree(root, 0);
    }
};

int main() {
    TourTree tours;
    tours.createRoot("World Tours");
    tours.addSubPackage("World Tours", "Asia Tours", "Europe Tours");
    tours.addSubPackage("Asia Tours", "Pakistan Tour", "Japan Tour");
    tours.addSubPackage("Europe Tours", "France Tour", "Italy Tour");
    tours.display();
    return 0;
}
