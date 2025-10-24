
#include <iostream>
#include <string>
using namespace std;

class StudentList {
private:
    struct Node {
        string name;
        int marks;
        Node* next;
    };

    Node* head; 

    int getDigit(int num, int place) {
        return (num / place) % 10;
    }

public:
    StudentList() {
        head = nullptr;
    }

    void addStudent(string naam, int number) {
        Node* naya = new Node{naam, number, nullptr};
        if (head == nullptr) {
            head = naya;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = naya;
    }

    void showList() {
        if (head == nullptr) {
            cout << "List khaali hai!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << temp->marks << endl;
            temp = temp->next;
        }
    }

    void radixSort() {
        if (!head || !head->next)
            return;

        int maxMarks = 100; 
        int place = 1;    

        while (maxMarks / place > 0) {
            Node* bucket[10] = {nullptr}; 
            Node* tail[10] = {nullptr};

            Node* current = head;
            while (current != nullptr) {
                int digit = getDigit(current->marks, place);
                Node* agla = current->next;
                current->next = nullptr;

                if (bucket[digit] == nullptr) {
                    bucket[digit] = current;
                    tail[digit] = current;
                } else {
                    tail[digit]->next = current;
                    tail[digit] = current;
                }
                current = agla;
            }

            head = nullptr;
            Node* last = nullptr;

            for (int i = 0; i < 10; i++) {
                if (bucket[i] != nullptr) {
                    if (head == nullptr) {
                        head = bucket[i];
                        last = tail[i];
                    } else {
                        last->next = bucket[i];
                        last = tail[i];
                    }
                }
            }

            place *= 10;
        }
    }
};

int main() {
    StudentList list;

    list.addStudent("Rizwan", 75);
    list.addStudent("Babar", 60);
    list.addStudent("Shan", 90);
    list.addStudent("Fakhar", 45);
    list.addStudent("Sarfraz", 85);
    list.addStudent("Haris", 92);
    list.addStudent("Shaheen", 70);

    cout << "Marks before sorting:\n";
    list.showList();

    list.radixSort();

    cout << "\nMarks after sorting :\n";
    list.showList();

    return 0;
}
