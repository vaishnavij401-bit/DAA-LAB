#include <iostream>
#include <algorithm>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;

    // Create array
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    // Enter elements
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Element to search
    cout << "Enter element to be searched: ";
    cin >> key;

    // Linear Search
    int linearResult = linearSearch(arr, n, key);

    if (linearResult != -1)
        cout << "Linear Search: Element found at index "
             << linearResult << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Sort the array
    sort(arr, arr + n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Binary Search
    int binaryResult = binarySearch(arr, n, key);

    if (binaryResult != -1)
        cout << "Binary Search: Element found at index "
             << binaryResult << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    // Comparison
    cout << "\nComparison:" << endl;
    cout << "Linear Search: O(n)" << endl;
    cout << "Binary Search: O(log n)" << endl;

    return 0;
}
