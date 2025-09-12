#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t size;

    void resize() {
        size_t new_capacity = capacity * 2;
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DynamicArray(size_t initial_capacity = 4)
        : capacity(initial_capacity), size(0) {
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(const T& element) {
        if (size == capacity) {
            resize();
        }
        data[size++] = element;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
};

int main() {
    DynamicArray<int> arr;
    for (int i = 1; i <= 10; ++i) {
        arr.push_back(i);
    }
    arr.print();
    return 0;
}
