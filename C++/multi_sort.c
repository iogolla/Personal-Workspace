// File      : mutli_sort.c
// Purpose   : To write and test (1) If a given Array is sorted
//             (2) Sort an Array using different sorting methods: quick sort,
//             bubble sort, selection sort, and merge sort
// Written by: Ian Ogolla
// Date      : Feb 20, 2019

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define N 20

bool sorted(int n, int A[]);	// Is A[] sorted?
void shuffle(int n, int A[]);	// Shuffle A (uses Fisher-Yates algorithm)
int randint(int a, int b);	// returns [a..b)
void swap(int A[], int i, int j); //swap the elements of the array
void quickSort(int A[], int low, int high); //Quick Sort
int partition(int A[], int low, int high); //partition an array into two groups
void bubbleSort(int A[], int n); 
void selectionSort(int A[], int n);
void merge(int A[],int i1,int j1,int i2,int j2);
void mergesort(int A[],int i,int j);


int main(void) {
    int data[N]; //create an array with 20 elements and name it data
    
    srand(time(NULL)); //seed generation for pseudo-random numbers 
    // initialize data so that data[i] = random interger
    for (int i=0; i < N; i++)
        data[i] = rand() % 100 + 1;//range from 1 to 100
    // Print contents of data and check whether or not it's sorted
    printf("Initial Array:\n"); 
    for (int i=0; i < N; i++)
        printf("%2d ", data[i]);
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));

    //sort data with quick sort
    quickSort(data, 0, N-1);
    printf("Sorted with quick sort:\n");
    for (int i = 0; i < N; i++)
        printf("%2d ", data[i]);
    // Print contents of data and check whether or not it's sorted
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));
    
    
    // Shuffle data, print contents of data and check whether or not it's sorted
    shuffle(N, data);
    printf("Shuffled Array:\n"); 
    for (int i=0; i < N; i++)
        printf("%2d ", data[i]); 
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));

    // Sort data with bubblesort
    bubbleSort(data, N);
    printf("Sorted with bubble sort:\n");
    for (int i = 0; i < N; i++)
        printf("%2d ", data[i]);
    // Print contents of data and check whether or not it's sorted
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));
    
    // Shuffle data, print contents of data and check whether or not it's sorted
    shuffle(N, data);
    printf("Shuffled Array:\n"); 
    for (int i=0; i < N; i++)
        printf("%2d ", data[i]); 
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));
    
    //sort with selection sort
    selectionSort(data, N);
    printf("Sorted with selection sort:\n");
    for (int i = 0; i < N; i++)
        printf("%2d ", data[i]);
    // Print contents of data and check whether or not it's sorted
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));
    
    // Shuffle data, print contents of data and check whether or not it's sorted
    shuffle(N, data);
    printf("Shuffled Array:\n"); 
    for (int i=0; i < N; i++)
        printf("%2d ", data[i]); 
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));

    //sort with merge sort
    mergesort(data, 0, N-1);
    printf("Sorted with merge sort:\n");
    for (int i = 0; i < N; i++)
        printf("%2d ", data[i]);
    // Print contents of data and check whether or not it's sorted
    printf("%s.\n", (sorted(N, data) ? "Sorted" : "Not Sorted"));

    return 0;
}//main() 

//Quick sort algorithm from Kings textbook pp. 207-209
void quickSort(int A[], int low, int high)
{   //low and high keep track of positions within the array
    int middle;
 	   
    if (low >= high) return;
 	 
    //partition array into two groups
    middle = partition(A, low, high);
 	 
    //sort array recursively right before the middle part
    quickSort(A, low, middle - 1);
 	 
    //sort array recursively right after the middle part
    quickSort(A, middle + 1, high);
    
}//quickSort()

int partition(int A[], int low, int high)
{
    int part_element = A[low]; //first element is the partitioning element
    
    //keep looking at the element pointed to by the low pointer and compare it with
    //the partitioning element
    for (;;)
    {
        while (low < high && part_element <= A[high])
            high--; //move the pointer of the high element to the previous element
        if (low >= high) break;
        A[low++] = A[high];
        
        while (low < high && A[low] <= part_element)
            low++; // move the pointer of the low element to the next element
        if (low >= high) break;
        A[high--] = A[low];
    }
    A[high] = part_element;
    return high;  
}//partition()
    
//Bubblesort Algorithm
void bubbleSort(int A[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)       
  
       // Swap the adjacent elements that are in wrong order    
       for (j = 0; j < n-i-1; j++)  
           //swap two consecutive integers if the current one is greater
           //than the next one
           if (A[j] > A[j+1]) 
              swap(A, j, j+1); 
}//bubbleSort()

//Selection sort algorithm
void selectionSort(int A[], int n) 
{ 
    int i, j, min; 
  
     
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in array 
        min = i; //minimum element
        for (j = i+1; j < n; j++) 
            //keep looking for the minimum element
            if (A[j] < A[min]) 
                min = j; 
  
        //Place the minimum element at the beginning of the array 
        swap(A, i , min); 
    } 
}//selectionSort()

//Merge sort algorithm
void mergesort(int A[],int i,int j)
{
	  int middle;
		
	  if(i<j)
	  {
		    middle=(i+j)/2; //split the elements of the array into two groups
		    mergesort(A,i,middle);//mergesort and recurse 
		    mergesort(A,middle+1,j);//mergesort and recurse
		    merge(A,i,middle,middle+1,j);	//merge the two sorted arrays
                                      //using the merge algorithm
	  }
}//mergesort()
 
void merge(int A[],int i1,int j1,int i2,int j2)
{
	  int tempA[N];	//create an array that will be used for merging
	  
    // i1 marks the start of the first array
    // i2 marks the start of the second array
    int i = i1,j = i2,k = 0;
	
	  while(i<=j1 && j<=j2)	//elements in both arrays
	  {
		    //add the elements of the two arrays to the merging array in ascending order
        if(A[i]<A[j])
			      tempA[k++]=A[i++];
		    else
            tempA[k++]=A[j++];
	  }
	
	  while(i<=j1)	//add remaining elements of the first array to the merging array, in
                  //ascending order
		{
        tempA[k++]=A[i++];
		}
	  while(j<=j2)	//add remaining elements of the second array to the merging array, in
                  //ascending order
		{
        tempA[k++]=A[j++];
		}
    //put the elements back to the original array
    for(i=i1,j=0;i<=j2;i++,j++)
		    A[i]=tempA[j];
}//merge()

bool sorted(int n, int A[]) // Check if array is sorted 
{ 
    for (int i=1; i < n; i++)
        if (A[i-1] > A[i])
             return false;
    return true;
} // sorted()

void shuffle(int n, int A[]) {	// Shuffle A[] (uses Fisher-Yates algorithm)
    for (int i=0; i <= n-2; i++) {
        int j = randint(i, n);
        swap(A, i, j);
    }
} // shuffle()

int randint(int a, int b) // returns [a..b)
{	
    return (int) (a + (rand() % (b-a)));
} // randint()

void swap(int A[], int i, int j) //swap two integers
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
} // swap()


