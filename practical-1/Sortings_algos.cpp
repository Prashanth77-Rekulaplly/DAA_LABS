#include <iostream>
using namespace std;

// ---------------- BUBBLE SORT ----------------
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// ---------------- SELECTION SORT ----------------
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// ---------------- INSERTION SORT ----------------
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// ---------------- MERGE SORT ----------------
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// ---------------- QUICK SORT ----------------
int partition(int arr[], int low, int high)
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

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// ---------------- DISPLAY ----------------
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// ---------------- MAIN ----------------
int main()
{
    int n;
    int original[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> original[i];

    int bubble[100], selection[100], insertion[100];
    int mergeArr[100], quick[100];

    // Copy original array
    for (int i = 0; i < n; i++)
    {
        bubble[i] = original[i];
        selection[i] = original[i];
        insertion[i] = original[i];
        mergeArr[i] = original[i];
        quick[i] = original[i];
    }

    // Sorting
    bubbleSort(bubble, n);
    selectionSort(selection, n);
    insertionSort(insertion, n);
    mergeSort(mergeArr, 0, n - 1);
    quickSort(quick, 0, n - 1);

    // Display results
    cout << "\nBubble Sort:    ";
    display(bubble, n);

    cout << "Selection Sort: ";
    display(selection, n);

    cout << "Insertion Sort: ";
    display(insertion, n);

    cout << "Merge Sort:     ";
    display(mergeArr, n);

    cout << "Quick Sort:     ";
    display(quick, n);

    return 0;
}