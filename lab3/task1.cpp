#include <iostream>
#include <string>
using namespace std;

struct Node {
    string book;
    Node* next;
    Node(string b) : book(b), next(nullptr) {}
};

class BookList {
private:
    Node* head;

public:
    BookList() : head(nullptr) {}

    void initialize() {
        add_back("Data Structures");
        add_back("Operating Systems");
        add_back("Computer Networks");
        add_back("Database Systems");
    }

    void add_front(const string& book) {
        Node* new_node = new Node(book);
        new_node->next = head;
        head = new_node;
    }

    void add_back(const string& book) {
        Node* new_node = new Node(book);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void insert_after(const string& target, const string& book) {
        Node* temp = head;
        while (temp) {
            if (temp->book == target) {
                Node* new_node = new Node(book);
                new_node->next = temp->next;
                temp->next = new_node;
                return;
            }
            temp = temp->next;
        }
    }

    bool search(const string& book) {
        Node* temp = head;
        while (temp) {
            if (temp->book == book)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        cout << "Book List:\n";
        while (temp) {
            cout << "- " << temp->book << "\n";
            temp = temp->next;
        }
    }

    ~BookList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    BookList library;
    library.initialize();

    library.add_front("Artificial Intelligence");
    library.add_back("Machine Learning");
    library.insert_after("Operating Systems", "Cyber Security");

    string search_title = "Database Systems";
    if (library.search(search_title)) {
        cout << search_title << " found in the library.\n";
    } else {
        cout << search_title << " not found in the library.\n";
    }

    library.display();

    return 0;
}
