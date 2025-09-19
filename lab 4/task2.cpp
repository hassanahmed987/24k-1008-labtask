#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int bubbleSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return comparisons;
}

int insertionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int selectionSort(int arr[], int n) {
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
    return comparisons;
}

int shellSort(int arr[], int n) {
    int comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}


void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0)); 

    
    int n1 = 20;
    int arr20[n1];
    for (int i = 0; i < n1; i++) {
        arr20[i] = rand() % 100 + 1; 
    }

    cout << "Original Array (20 elements): ";
    printArray(arr20, n1);

    int temp[100]; 

    // Bubble Sort
    copyArray(arr20, temp, n1);
    int bubbleComp = bubbleSort(temp, n1);
    cout << "\nBubble Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons = " << bubbleComp << endl;

    // Insertion Sort
    copyArray(arr20, temp, n1);
    int insertionComp = insertionSort(temp, n1);
    cout << "\nInsertion Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons = " << insertionComp << endl;

    // Selection Sort
    copyArray(arr20, temp, n1);
    int selectionComp = selectionSort(temp, n1);
    cout << "\nSelection Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons = " << selectionComp << endl;

    // Shell Sort
    copyArray(arr20, temp, n1);
    int shellComp = shellSort(temp, n1);
    cout << "\nShell Sort Result: ";
    printArray(temp, n1);
    cout << "Comparisons = " << shellComp << endl;

    // doing same with 100 random numbers
    int n2 = 100;
    int arr100[n2];
    for (int i = 0; i < n2; i++) {
        arr100[i] = rand() % 100 + 1;
    }

    cout << "\n\nOriginal Array (100 elements): ";
    printArray(arr100, n2);

    // Bubble Sort (100 elements) 
    copyArray(arr100, temp, n2);
    bubbleComp = bubbleSort(temp, n2);
    cout << "\nBubble Sort Result (100 elements): ";
    printArray(temp, n2);
    cout << "Comparisons = " << bubbleComp << endl;

    // Insertion Sort (100 elements)
    copyArray(arr100, temp, n2);
    insertionComp = insertionSort(temp, n2);
    cout << "\nInsertion Sort Result (100 elements): ";
    printArray(temp, n2);
    cout << "Comparisons = " << insertionComp << endl;

    // Selection Sort (100 elements)
    copyArray(arr100, temp, n2);
    selectionComp = selectionSort(temp, n2);
    cout << "\nSelection Sort Result (100 elements): ";
    printArray(temp, n2);
    cout << "Comparisons = " << selectionComp << endl;

    // Shell Sort (100 elements)
    copyArray(arr100, temp, n2);
    shellComp = shellSort(temp, n2);
    cout << "\nShell Sort Result (100 elements): ";
    printArray(temp, n2);
    cout << "Comparisons = " << shellComp << endl;

    return 0;
}
