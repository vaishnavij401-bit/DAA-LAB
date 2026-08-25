#include <iostream>
using namespace std;

// ---------- Selection Sort ----------
void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

// ---------- Merge Function ----------
void merge(int arr[], int low, int mid, int high) {

    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {

        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp back to original array
    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// ---------- Merge Sort ----------
void mergeSort(int arr[], int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// ---------- Quick Sort Partition ----------
int partition(int arr[], int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {

            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// ---------- Quick Sort ----------
void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);

        quickSort(arr, p + 1, high);
    }
}

// ---------- Main ----------
int main() {

    int n, choice;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements of array: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Merge Sort\n";
    cout << "3. Quick Sort\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {

        selectionSort(arr, n);

    }
    else if (choice == 2) {

        mergeSort(arr, 0, n - 1);

    }
    else if (choice == 3) {

        quickSort(arr, 0, n - 1);

    }
    else {

        cout << "Invalid choice!";
        return 0;
    }

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
