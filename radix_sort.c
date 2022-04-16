
#include <stdio.h>
#include <stdlib.h>

void cumulative_addition(int count_array[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        count_array[i+1]=count_array[i]+count_array[i+1];
    }
}

void zero_initialize(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        array[i]=0;
    }
}


// From previous code counting sort has been used 
void countingsort(int array[], int size, int place) {

  int output[size + 1];
  int max = (array[0] / place) % 10;//initialzing with first value

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];//declaring a counter matrix with size max+1
zero_initialize(count,max+1);
 
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

cumulative_addition(count,10);


  for (int i = size - 1; i >= 0; i--) 
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

  for (int i = 0; i < size; i++)
  {
    array[i] = output[i];
  }
}


// Function to print the array
void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void random_initialization(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        array[i]=rand()%100;
    }
}


int maximum_value_in_array(int array[], int size) 
{
  int maximum = array[0];//initialize with first element of array
  for (int i = 1; i < size; i++)
    {
    if (array[i] > maximum)
      maximum = array[i];
    }
  return maximum;
}




// Main function to implement radix sort
void radixsort(int array[], int size) {
 //calculate the maximum element in the array
  int largest_element = maximum_value_in_array(array, size);

  //From the previous question the counting sort algorithm would be used
  for (int place = 1; largest_element / place > 0; place *= 10)
    countingsort(array, size, place);
}


// Main Code
int main() {
    int size;
    printf("enter size of array \n");
    scanf("%d",&size);
  int array[size];
  random_initialization(array,size);
  printf("beofre sorting \n");

  printArray(array, size);
  radixsort(array, size);
  printf("after sorting \n");
  printArray(array, size);
}
