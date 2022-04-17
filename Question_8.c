#include <stdio.h>
#include <stdlib.h>


// Function to print the array
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


void swap_two_numbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int n, int i) {
    if(n!=0) {
        printf("Intermediate traversals \n");
        printArray(arr, n);
    }
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
 // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap_two_numbers(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void Heap_sort(int arr[], int n) {
    for (int i = (n/2) - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap_two_numbers(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}


void random_initialization(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        array[i]=rand()%100;
    }
}


int main() {
  int size;
    printf("enter size of array \n");
    scanf("%d",&size);
  int array[size];
  random_initialization(array,size);
  printArray(array, size);
    Heap_sort(array, size);
    printf("Final obtained ascended sorted array is \n");
    printArray(array, size);
}
