// File      : mutli_sort.c
// Purpose   : Prompts the user for a number and then displays the number
//             using characters to simulate the effect of a 7-segment display
// Written by: Ian Ogolla
// Date      : March 6, 2019

	 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_DIGITS 10 //controller for number of digits
#define MAX_SEGMENTS 7
#define ROWS 3


int digit[MAX_DIGITS]; 
//puting in place the position of the lines
const int segments[MAX_DIGITS][MAX_SEGMENTS] ={
	{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {0,0,1,1,1,1,1}, {1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1}, {1,1,1,0,0,1,1}};

char digits[ROWS][MAX_DIGITS * 4];// array of characters with 4 rows and 4 columns
void clear_digit_array(void);
void process_digit(int digit, int position);
void print_digit_array(void);



int main(void)
{
	char ch;
  int count; //counter
	
  
	clear_digit_array(); // putting blank: ' ' characters into the digit array

	//prompt the user for input
	printf("Enter a number : ");
  
  count = 0; //initialize the counter
  
  //read a number input from user
  while ((ch = getchar()) != '\n' && count < MAX_DIGITS) 
  {
        if (isdigit(ch)) 
        //isdigit checks if the passed character is a decimal digit character
        //isdigit ignores characters that are not digits (e.g alphabets)
        {
            //Store the 7-segment representation of digit into a specified position
            //in the digits array
            process_digit(ch - '0', count);
            count += 1;
           
        }
        
    }//end loop

    print_digit_array();
    return 0;
}// end of main()


//put blank characters: ' ' into the elements of the digits array
void clear_digit_array(void)
{
    //go throught all the elements of the digits array
    for (int i = 0; i < MAX_DIGITS; ++i)
		    for (int j = 0; j < MAX_DIGITS * 4; ++j)
			      digits[i][j] = ' ';

}//end of clear_digit_array()

//Store the 7-segment repsresentation of digit into a specified position
//in the digits array
void process_digit(int digit, int position)
{
	int i;
  //position*4 sums the column on the matrix (3 for segments
  // and 1 for space)
  int maxcolumn = position*4;
    for(i=0;i<MAX_SEGMENTS;i++){
        //digit is an index into the segments
        if(segments[digit][i]==1) 
            switch(i){
                
                case 0: digits[0][1+maxcolumn]='_'; //put an underbar
                break;
                case 1: digits[1][2+maxcolumn]='|'; //put a horizontal underbar
                break;
                case 2: digits[2][2+maxcolumn]='|'; //put a horizontal underbar
                break;
                case 3: digits[2][1+maxcolumn]='_'; //put an underbar
                break;
                case 4: digits[2][0+maxcolumn]='|'; //put a horizontal underbar
                break;
                case 5: digits[1][0+maxcolumn]='|'; //put a horizontal underbar
                break;
                case 6: digits[1][1+maxcolumn]='_'; //put an underbar
                break;
            }
    }
}//end of process_digit()

//Display the rows of the digits array, each on a single line, and produce an output
void print_digit_array(void)
{
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < MAX_DIGITS * 4; ++j)
			printf("%c", digits[i][j]);
		printf("\n");
	}
}//end of print_digit_array()
