#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void push_back(int val) {
        Node* new_node = new Node(val);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new_node;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void sort() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    void concatenate(LinkedList& other) {
        if (!head) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = other.head;
        }
        other.head = nullptr; 
    }

    int find_middle() const {
        if (!head) throw runtime_error("List is empty");
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void remove_duplicates() {
        Node* current = head;
        while (current) {
            Node* runner = current;
            while (runner->next) {
                if (runner->next->data == current->data) {
                    Node* dup = runner->next;
                    runner->next = runner->next->next;
                    delete dup;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    static LinkedList merge_sorted(LinkedList& l1, LinkedList& l2) {
        LinkedList merged;
        Node* p1 = l1.head;
        Node* p2 = l2.head;
        Node dummy(0);
        Node* tail = &dummy;

        while (p1 && p2) {
            if (p1->data < p2->data) {
                tail->next = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        tail->next = (p1) ? p1 : p2;

        merged.head = dummy.next;
        l1.head = nullptr;
        l2.head = nullptr;
        return merged;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1;
    list1.push_back(3);
    list1.push_back(1);
    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(3);

    cout << "Original List 1: ";
    list1.print();

    list1.sort();
    cout << "Sorted List 1: ";
    list1.print();

    list1.remove_duplicates();
    cout << "After removing duplicates from List 1: ";
    list1.print();

    LinkedList list2;
    list2.push_back(6);
    list2.push_back(5);
    list2.push_back(8);

    cout << "Original List 2: ";
    list2.print();

    list2.sort();
    cout << "Sorted List 2: ";
    list2.print();

    cout << "Concatenating List 2 to List 1:\n";
    list1.concatenate(list2);
    cout << "Concatenated List: ";
    list1.print();

    cout << "Middle element of the concatenated list: " << list1.find_middle() << "\n";

    LinkedList sorted1;
    sorted1.push_back(1);
    sorted1.push_back(3);
    sorted1.push_back(5);

    LinkedList sorted2;
    sorted2.push_back(2);
    sorted2.push_back(4);
    sorted2.push_back(6);

    cout << "Sorted List A: ";
    sorted1.print();

    cout << "Sorted List B: ";
    sorted2.print();

    LinkedList merged = LinkedList::merge_sorted(sorted1, sorted2);
    cout << "Merged Sorted List: ";
    merged.print();

    return 0;
}
