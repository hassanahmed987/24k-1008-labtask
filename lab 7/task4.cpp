#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
Node* partition(Node* start, Node* end) {
    if (start == end || !start || !end)
        return start;

    Node* pivot = end;
    Node* prev = start;
    Node* curr = start;
    Node* tail = pivot;

    Node* pIndex = start;

    while (curr != end) {
        if (curr->data < pivot->data) {
            swap(curr, pIndex);
            pIndex = pIndex->next;
        }
        curr = curr->next;
    }

    swap(pIndex, pivot);
    return pIndex;
}

void quickSortRec(Node* start, Node* end) {
    if (!start || start == end || start == end->next)
        return;
    Node* pivot = partition(start, end);

    Node* temp = start;
    while (temp->next != pivot && temp->next)
        temp = temp->next;

    if (temp != pivot)
        quickSortRec(start, temp);
    quickSortRec(pivot->next, end);
}

Node* getTail(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

void quickSort(Node*& head) {
    Node* tail = getTail(head);
    quickSortRec(head, tail);
}

int main() {
    Node* head = nullptr;

    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insert(head, arr[i]);

    cout << "Original List: ";
    printList(head);
    quickSort(head);

    cout << "Sorted List:   ";
    printList(head);

    return 0;
}
