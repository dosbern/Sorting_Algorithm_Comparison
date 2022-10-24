// Assignment3Q4.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//declare arrays
int arrayOne[1000] = {};
int arrayTwo[1000] = {};
int arrayThree[1000] = {};

//populate arrays with random numbers
void populate(int arr, int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        arrayOne[i] = rand() % 1000;
    }

    for (int i = 0; i < (size - 1); i++)
    {
        arrayTwo[i] = rand() % 1000;
    }

    for (int i = 0; i < (size - 1); i++)
    {
        arrayThree[i] = rand() % 1000;
    }
}

//bubble sort algorithm
void sortBubble(int* arr, int size)
{
    int counter = 0;
    for (int i = 0; i < (size - 1); i++)
{ 
       for (int j = 0; j < (size - i - 1); j++)
       {
           if (arr[j] > arr[j + 1])
           { 
              int temp = arr[j];
              arr[j] = arr[j + 1];
              arr[j + 1] = temp;
              counter++;
           } 
      }
    }
    cout << "Bubble sort count = " << counter << endl;
}

//shell sort algorithm
void sortShell(int* arr, int n)
{
    int counter = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
            arr[j] = arr[j - gap];
            counter++;
            }
            arr[j] = temp;
        }
    }
    cout << "Shell sort count = " << counter << endl;
}

//quick sort algorithm
int quickSortCounter = 0;

void swap(int& x, int& y)
{
    int temp = y;
    y = x;
    x = temp;
    quickSortCounter++;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }    
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//merge sort algorithm
int mergeSortCounter = 0;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* create temp arrays */
    int* L = new int[n1];
    int* R = new int[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
    R[j] = arr[m + 1 + j];
    }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            mergeSortCounter++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            mergeSortCounter++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//selection sort algorithm
void sortSelection(int* arr, int size)
{
    int counter = 0;
    for (int i = 0; i < size - 1; i++) 
{
        int min = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            counter++;
        }
    }
    cout << "Selection sort count = " << counter << endl;
}

int main()
{
    srand(time(0));

    //bubble sort
    populate(*arrayOne, 1000);
    populate(*arrayTwo, 1000);
    populate(*arrayThree, 1000);

    sortBubble(arrayOne, 1000);
    sortBubble(arrayTwo, 1000);
    sortBubble(arrayThree, 1000);

    //quick sort
    populate(*arrayOne, 1000);
    populate(*arrayTwo, 1000);
    populate(*arrayThree, 1000);

    quickSort(arrayOne, 1, 1000);
    cout << "Quick sort counter = " << quickSortCounter << endl;
    quickSortCounter = 0;
    quickSort(arrayTwo, 1, 1000);
    cout << "Quick sort counter = " << quickSortCounter << endl;
    quickSortCounter = 0;
    quickSort(arrayThree, 1, 1000);
    cout << "Quick sort counter = " << quickSortCounter << endl;

    //shell sort
    populate(*arrayOne, 1000);
    populate(*arrayTwo, 1000);
    populate(*arrayThree, 1000);

    sortShell(arrayOne, 1000);
    sortShell(arrayTwo, 1000);
    sortShell(arrayThree, 1000);

    //merge sort
    populate(*arrayOne, 1000);
    populate(*arrayTwo, 1000);
    populate(*arrayThree, 1000);

    mergeSort(arrayOne, 0, 999);
    cout << "Merge sort counter = " << mergeSortCounter << endl;
    mergeSortCounter = 0;
    mergeSort(arrayTwo, 0, 999);
    cout << "Merge sort counter = " << mergeSortCounter << endl;
    mergeSortCounter = 0;
    mergeSort(arrayThree, 0, 999);
    cout << "Merge sort counter = " << mergeSortCounter << endl;

    //selection sort
    populate(*arrayOne, 1000);
    populate(*arrayTwo, 1000);
    populate(*arrayThree, 1000);

    sortSelection(arrayOne, 1000);
    sortSelection(arrayTwo, 1000);
    sortSelection(arrayThree, 1000);

    system("pause");
    return 0;
}