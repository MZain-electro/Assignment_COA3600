
#include <stdio.h>
#include <stdlib.h>

void random_initialization(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        array[i]=rand()%100;
    }
}

void printArray(int array[], int size) 
{
  for (int i = 0; i < size; ++i) 
    {
        printf("%d  ", array[i]);
    }
  printf("\n");
}

int maximum_value_in_array(int array[], int size) 
{
  int maximum = array[0];//initialize
  for (int i = 1; i < size; i++)
    {
    if (array[i] > maximum)
      maximum = array[i];
    }
  return maximum;
}

void position_filling(int array[], int size, int count_array[], int count_array_size)
{
    for (int i=0;i<count_array_size;i++)//initialize all elements to 0
    {
        count_array[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        count_array[array[i]]=count_array[array[i]]+1;
    }
}

void cumulative_addition(int count_array[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        count_array[i+1]=count_array[i]+count_array[i+1];
    }
}

void places(int places[],int array[], int count_array[], int size, int size_of_count_array)
{
for(int i=0;i<size;i++)
{
    places[count_array[array[i]]-1]=array[i];
    count_array[array[i]]=count_array[array[i]]-1;
}
}

// Main Code
int main() {
    int size;
    printf("enter size of array \n");
    scanf("%d",&size);
  int array[size];
   random_initialization(array,size);
   printf("Original Matrix is \n");
    printArray(array, size);
  int max=maximum_value_in_array(array,size);
  int count_array[max+1];//create an empty count_array
printf("value of max is %d",max);
  printf("\n");
  position_filling(array,size,count_array,max+1);
  printf("\n");
  printArray(count_array, max+1);
  cumulative_addition(count_array,max+1);
  printf("\n");
   printf("count_array is \n");
  printArray(count_array, max+1);
  int places_array[size];
  places(places_array,array,count_array,size,max+1);
  printf("Final Sorted Array is \n");
  printArray(places_array, size);

}
