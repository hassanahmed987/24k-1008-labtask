#include <iostream>
using namespace std;

struct Node {
    int compartmentNumber;
    Node* prev;
    Node* next;
    Node(int num) : compartmentNumber(num), prev(nullptr), next(nullptr) {}
};

class Train {
private:
    Node* head;
    Node* tail;

public:
    Train() : head(nullptr), tail(nullptr) {}

    void add_end(int num) {
        Node* new_node = new Node(num);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void remove_front() {
        if (!head) {
            cout << "Train is empty. No compartment to remove.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        cout << "Removed compartment: " << temp->compartmentNumber << "\n";
        delete temp;
    }

    void search(int num) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->compartmentNumber == num) {
                cout << "Compartment " << num << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            ++pos;
        }
        cout << "Compartment " << num << " not found.\n";
    }

    void display() {
        if (!head) {
            cout << "Train has no compartments.\n";
            return;
        }
        cout << "Compartments from front to end:\n";
        Node* temp = head;
        while (temp) {
            cout << temp->compartmentNumber << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~Train() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Train train;

    train.add_end(101);
    train.add_end(102);
    train.add_end(103);
    train.add_end(104);

    train.display();

    cout << "\nRemoving front compartment...\n";
    train.remove_front();

    train.display();

    cout << "\nSearching for compartment 103...\n";
    train.search(103);

    cout << "Searching for compartment 999...\n";
    train.search(999);

    return 0;
}
