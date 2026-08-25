#include <iostream>
using namespace std;

class HeapSort
{
public:
    int arr[50], size;

    void inputArray()
    {
        cout << "Enter size of array: ";
        cin >> size;

        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void MaxHeapify(int arr[], int size, int i)
    {
        int largest = i;

        int l = (2 * i) + 1;
        int r = (2 * i) + 2;

        if (l < size && arr[l] > arr[largest])
        {
            largest = l;
        }

        if (r < size && arr[r] > arr[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);

            MaxHeapify(arr, size, largest);
        }
    }

    void heapSort()
    {
        // Build Max Heap
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            MaxHeapify(arr, size, i);
        }

        // Heap Sort
        for (int i = size - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);

            MaxHeapify(arr, i, 0);
        }
    }

    void printArray()
    {
        cout << "Sorted array: ";

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    HeapSort obj;

    obj.inputArray();
    obj.heapSort();
    obj.printArray();

    return 0;
}