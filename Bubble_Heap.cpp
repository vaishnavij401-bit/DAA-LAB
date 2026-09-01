#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ----------- BUBBLE SORT -----------
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


// ----------- HEAP SORT -----------

// Heapify function
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

        // Heapify affected subtree
        heapify(arr, n, largest);
    }
}


// Heap Sort function
void heapSort(vector<int>& arr)
{
    int n = arr.size();

    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move largest element to end
        swap(arr[0], arr[i]);

        // Heapify remaining array
        heapify(arr, i, 0);
    }
}


// ----------- DISPLAY FUNCTION -----------
void display(vector<int>& arr)
{
    for (int i : arr)
    {
        cout << i << " ";
    }

    cout << endl;
}


// ----------- MAIN FUNCTION -----------
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
    cout << "2. Heap Sort\n";

    cout << "Enter your choice: ";
    cin >> choice;


    switch (choice)
    {
        case 1:
            bubbleSort(arr);
            cout << "Sorted using Bubble Sort: ";
            break;

        case 2:
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
