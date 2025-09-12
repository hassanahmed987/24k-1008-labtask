#include <iostream>
#include <string>
using namespace std;

struct Node {
    string book;
    Node* next;
    Node(const string& b) : book(b), next(nullptr) {}
};

class LibraryCatalog {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    LibraryCatalog() : head(nullptr), tail(nullptr), size(0) {}

    void add_tail(const string& book) {
        Node* new_node = new Node(book);
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        ++size;
    }

    void delete_front() {
        if (!head) {
            cout << "Catalog is empty. Nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        cout << "Deleted book: " << temp->book << "\n";
        delete temp;
        --size;
    }

    void search_by_title(const string& title) {
        Node* temp = head;
        size_t pos = 1;
        while (temp) {
            if (temp->book == title) {
                cout << "Book found at position " << pos << ": " << temp->book << "\n";
                return;
            }
            temp = temp->next;
            ++pos;
        }
        cout << "Book titled \"" << title << "\" not found.\n";
    }

    void search_by_position(size_t pos) {
        if (pos == 0 || pos > size) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        for (size_t i = 1; i < pos; ++i) {
            temp = temp->next;
        }
        cout << "Book at position " << pos << ": " << temp->book << "\n";
    }

    void display() const {
        if (!head) {
            cout << "Catalog is empty.\n";
            return;
        }
        cout << "Library Catalog:\n";
        Node* temp = head;
        size_t pos = 1;
        while (temp) {
            cout << pos << ". " << temp->book << "\n";
            temp = temp->next;
            ++pos;
        }
    }

    ~LibraryCatalog() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LibraryCatalog catalog;

    catalog.add_tail("Data Structures");
    catalog.add_tail("Operating Systems");
    catalog.add_tail("Computer Networks");
    catalog.add_tail("Database Systems");

    catalog.display();

    cout << "\nAdding \"Artificial Intelligence\" to tail.\n";
    catalog.add_tail("Artificial Intelligence");
    catalog.display();

    cout << "\nDeleting from front.\n";
    catalog.delete_front();
    catalog.display();

    cout << "\nSearching for book titled \"Database Systems\".\n";
    catalog.search_by_title("Database Systems");

    cout << "\nSearching for book at position 3.\n";
    catalog.search_by_position(3);

    return 0;
}
