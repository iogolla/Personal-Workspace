// File      : strings.c
// Purpose   : Prompts user for strings, compares their lexicographical order, 
//             and sorts them using bubble sort algorithm
// Written by: Ian Ogolla
// Date      : April 1, 2019
#include <stdio.h>

#define MAX_LEN 22
#define NUM_STRINGS 10

int scompare(char * str1, char * str2);
int length (char mystr[]);
void fixfgetstring(char mystr[]);
void swap(char *str1, char *str2);
void bubbleSort(char *array, int num_strings, int max_len);

int main()
{
    char string[NUM_STRINGS][MAX_LEN]; // create a 2D array

    //Prompt user for srtrings
    printf("Enter %d strings, separated by linefeeds:\n", NUM_STRINGS);
    
    int count = 0;//to keep track of the number of strings user puts in array
    while (count < NUM_STRINGS)
    {
        //read the lines of the strings into the string array and 
        //replace a linefeed with a null character
        fgets(*(string + count), MAX_LEN, stdin);
        fixfgetstring(*(string + count));
        count++; //keep track of the number of strings user inputs
    }//end while
    
    //sort the array lexicographically using bubblesort algorithm
    //and display the sorted array
    bubbleSort((char*) string, NUM_STRINGS, MAX_LEN); 
    printf("\nThe sorted array is:\n");
    for (int i = 0; i< NUM_STRINGS; i++)
        printf("%s\n", *(string + i));
}//end main

//This function returns the length of a given string
int length (char mystr[])
{
    char count = 0;
    char *i;
    
    
    //traverse the string using pointers
    for (i = mystr; *i != 0; i++)
        count++; //increment the count of characters in the string
    return (count); 
}//end length

//This function compares 2 strings lexicographically and  
//returns a negative number if string1 comes before string2
//lexicographically, a positive number is string1 comes
//after string2 lexicographically, and a zero if 
//both strings are equal 
int scompare(char * str1, char * str2)
{
    int i = 0;

    //compare the individual characters
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' && str2[i] == '\0')
            break;

        i++;
    }

    // Return the difference of characters in the strings.
    return str1[i] - str2[i];
}//end scompare


//This function traverses the string and replaces a linefeed with a null character
void fixfgetstring(char mystr[])
{
    char *ptr = mystr; //create a pointer to the string
    //look for a pointer that points to a linefeed and replace it with a null character 
    while (*ptr != '\n')
    {
        ptr++;
    }//end while
    *ptr = '\0';   
}//end fixfgetstring

//This function sorts the array of strings using bubble sort algorithm
//Some of this code is from the hint we were given
void bubbleSort(char *array, int num_strings, int max_len)
{
    int i, j;
    for(i = 0; i < (NUM_STRINGS - 1); i++) 
    {
        for(j = 0; j < (NUM_STRINGS - i - 1); j++) 
        {
            if(scompare(array + j * MAX_LEN, array + (j + 1) * MAX_LEN) > 0) 
            {
                swap(array + j * MAX_LEN, array + (j + 1) * MAX_LEN);
            } // end if
         } // end for
     } // end for 
}//end bubbleSort

//This function swaps the strings
void swap(char *str1, char *str2) //swap two characters
{
    char temp[MAX_LEN];//create a temporary array
    
    //transfer the contents of string1 into temp
    for (int i = 0; i < MAX_LEN; i++)
        *(temp + i) = *(str1 + i);
    //transfer the contents of string2 into string1
    for (int i = 0; i < MAX_LEN; i++)    
        *(str1 + i) = *(str2 + i);
    //transfer the contents of temp into string2
    for (int i = 0; i < MAX_LEN; i++)
        *(str2 + i) = *(temp + i);
} // swap()       