#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        // interpolation formula 
        int pos = low + ((double)(high - low) / 
                        (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1; 
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    cout << "\nSorted Array (Bubble Sort): ";
    printArray(arr, n);

    cout << "Enter element to search: ";
    cin >> key;

    int result = interpolationSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << " (0-based indexing)" << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
