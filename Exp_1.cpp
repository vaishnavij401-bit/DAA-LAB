#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ---------------- BUBBLE SORT ----------------
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


// ---------------- SELECTION SORT ----------------
void selectionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}


// ---------------- MERGE SORT ----------------
void merge(vector<int>& arr, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
    {
        arr[k] = temp[k - left];
    }
}


void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


// ---------------- QUICK SORT ----------------
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


// ---------------- HEAP SORT ----------------

// Function to convert subtree into Max Heap
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr)
{
    int n = arr.size();

    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from Heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move largest element to the end
        swap(arr[0], arr[i]);

        // Heapify remaining elements
        heapify(arr, i, 0);
    }
}


// ---------------- DISPLAY FUNCTION ----------------
void display(vector<int>& arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
}


// ---------------- MAIN FUNCTION ----------------
int main()
{
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    cout << "\nChoose Sorting Algorithm:\n";

    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Heap Sort\n";

    cout << "Enter your choice: ";
    cin >> choice;


    switch (choice)
    {
        case 1:
            bubbleSort(arr);
            cout << "Sorted using Bubble Sort: ";
            break;

        case 2:
            selectionSort(arr);
            cout << "Sorted using Selection Sort: ";
            break;

        case 3:
            mergeSort(arr, 0, n - 1);
            cout << "Sorted using Merge Sort: ";
            break;

        case 4:
            quickSort(arr, 0, n - 1);
            cout << "Sorted using Quick Sort: ";
            break;

        case 5:
            heapSort(arr);
            cout << "Sorted using Heap Sort: ";
            break;

        default:
            cout << "Invalid Choice!";
            return 0;
    }


    display(arr);

    return 0;
}
