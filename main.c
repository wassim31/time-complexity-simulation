#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"
void bubble_sort(int *array, int size);
void array_print(int *array, int size);
void array_init(int *array, int size);
int binary_search_recursive(int *array, int start, int finish, int searched_number);
int binary_search_iterative(int *array, int start, int finish, int searched_number);
void swap(int *a, int *b);
int main(void)
{
    clock_t t, t1;
    int size = 0, searched_element = 0;
    printf("how many  array's elements you want: ");
    scanf("%d", &size);

    // memory allocation for array in heap segement
    int *array = malloc(size * sizeof(int));
    printf("add values to your array:\n");
    array_init(array, size);
    t = clock();

    bubble_sort(array, size);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    t1 = clock();
    binary_search_recursive(array,0,size,4000);
    t1 = clock() - t1;
    double time_taken_1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

    printf("bubble_sort took %f seconds & binary_search took %f to execute for %d array items \n", time_taken,time_taken_1, size);
    
    // for bigger input now 
    printf("how many  array's elements you want: ");
    scanf("%d", &size);
    printf("add values to your array:\n");
    array_init(array, size);
    t = clock();

    bubble_sort(array, size);

    t = clock() - t;
     time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    t1 = clock();
    binary_search_recursive(array,0,size,4000);
    t1 = clock() - t1;
     time_taken_1 = ((double)t1)/CLOCKS_PER_SEC; // in seconds

    printf("bubble_sort took %f seconds & binary_search took %f to execute for %d array items \n", time_taken,time_taken_1, size);
/*
    array_print(array, size);
    printf("which element you're searching for: ");
    scanf("%d", &searched_element);
    // call binary_search function
    int final_result = binary_search_iterative(array, 0, size - 1, searched_element);
    if(final_result < 0)
    {
        printf("not found");
    }
    else
    {
        printf("it's situated in index : %d", final_result);
    }
    // de-allocate the allocated space in heap memory for the array
    */
    free(array);

    return 0;
}
void array_init(int *array, int size)
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        array[i] = (i*2)+1;
    }

}
void swap(int *a, int *b)
{
    if(*a > *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
void bubble_sort(int *array, int size)
{
    int i, j;
    for(i = 0 ; i < size -1 ; i++)
    {
        for(j = 0 ; j < size - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}
void array_print(int *array, int size)
{
    int i;
    for(i = 0 ; i < size ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int binary_search_recursive(int *array, int start, int finish, int searched_number)
{
    if(finish >= start)
    {
        int middle = (finish + start) / 2;

        if(array[middle] == searched_number)
            return middle;
        if(searched_number > array[middle])
            return binary_search_recursive(array, middle + 1, finish, searched_number);
        else
        return binary_search_recursive(array, start, middle - 1, searched_number);
    }
    return -1;
}
int binary_search_iterative(int *array, int start, int finish, int searched_number)
{
    while(finish >= start)
    {
        int middle = (finish+start)/2;
        if(searched_number == array[middle])
            return middle;
        else if(searched_number > array[middle])
            start = middle+1;
        else
            finish = middle-1;
    }
}