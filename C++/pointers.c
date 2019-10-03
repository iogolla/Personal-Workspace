// File      : pointers.c
// Purpose   : Prompts user for two values and fills an array with 16 random
//           : values between the two values, reports the minimum and maximum
//           : values, sorts the random values, and reports again the mimimum
//           : and maximum values and their positions
// Written by: Ian Ogolla
// Date      : March 21, 2019

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define N 17

void max_min(int a[], int n, int *max, int *min);
void quickSort(int A[], int *low, int *high); //Quick Sort
void Randoms(int a[], int min, int max, int n); // Generate random values
int *partition(int A[], int *low, int *high);


int main(void)
{
    int data[N], i, max, min;
    //Ask user for lowest value
    printf("What is the lowest value? \n", min);
    //Store the lowest value in the variable "min"
    scanf("%d", &min);
     //Ask user for highest value
    printf("What is the higest value? \n", max);
     //Store the highest value in the variable "max"
    scanf("%d", &max);
    
    srand(time(0));//seed generation for pseudo-random numbers
    
    
    printf("\n\nThe random values generated are:\n");
    Randoms(data, min, max, N);
    
    //Report the minimum and maximum vaues
    max_min(data, N, &max, &min);
    printf("\n\nThe minimum value is %d", min);
    printf("\nThe maximum value is %d", max);
    
    //sort data with quick sort and display the values
    quickSort(data, data, data + N - 1);
    printf("\n\nThe sorted values are:\n");
    for (int i = 0; i < N; i++)
        printf("%2d ", *(data + i));
    printf("\n");
        
    //Report the minimum and maximum vaues
    max_min(data, N, &max, &min);
    printf("\n\nThe minimum value is %d at %d", min, *(data - min));
    printf("\nThe maximum value is %d", max);
    
    printf("\n");

}
// Generate random values from the given minimum and maximum values(inclusive)
void Randoms(int a[], int min, int max, int n) 
{ 
    
    int i; 
    for (i = 0; i < n; i++) { 
        *(a + i) = (rand() % (max - min + 1)) + min; //range from min to max 
        printf("%d ", *(a + i)); //display the random values
    } 
    
} 

//find the largest and smallest elements int an array
void max_min(int a[], int n, int *max, int *min)
{
    int *i; //pointer
    
    *max = *min = a[0];
    for (i = a + 1; i < a + n; i++) //traverse the array using pointers
    {
        if (*i > *max)
            *max = *i;
        else if (*i < *min)
            *min = *i;
    }
}


//Quick sort algorithm from Kings textbook pp. 207-209
void quickSort(int A[], int *low, int *high)
{   //low and high keep track of positions within the array
    int *middle;
 	   
    if (low >= high) return;
 	 
    //partition array into two groups
    middle = partition(A, low, high);
 	 
    //sort array recursively right before the middle part
    quickSort(A, low, middle - 1);
 	 
    //sort array recursively right after the middle part
    quickSort(A, middle + 1, high);
    
}//quickSort()

int *partition(int A[], int *low, int *high)
{
    int part_element = *low; //first element is the partitioning element
    
    //keep looking at the element pointed to by the low pointer and compare it with
    //the partitioning element
    for (;;)
    {
        while (low < high && part_element <= *high)
            high--; //move the pointer of the high element to the previous element
        if (low >= high) break;
        *low++ = *high;
        
        while (low < high && *low <= part_element)
            low++; // move the pointer of the low element to the next element
        if (low >= high) break;
        *high-- = *low;
    }
    *high = part_element;
    return high;  
}//partition()

