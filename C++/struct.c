// File      : struct.c
// Purpose   : Creates a struct with elements from the periodic
//           : table and searches the element acording to user's
//           : preferred mode of search, that is, by element's
//           : name, symbol, or atomic number
// Written by: Ian Ogolla
// Date      : April 18, 2019


//library functions and macro definitions
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <string.h> 
#define ELEM_NAME 30 //length of element name
#define ELEM_CLASS 30 //lentght of the name of element's class
#define NUM_ELEMENTS 7 //number of elements in the array

//variable declarations
struct element_t
{
    int atomic_num;
    char name[ELEM_NAME];
    char symbol[3];
    char element_class[ELEM_CLASS];
    double atomic_weight;
    int elec[NUM_ELEMENTS];
} element_t;

//elements from the periodic table
struct element_t elements[] = 
{
    {11, "Sodium", "Na", "alkali_metals", 22.9898, {2,8,1,0,0,0,0}},
    {17, "Chlorine", "Cl", "halogen", 35.453, {2,8,7,0,0,0,0}},
    {13, "Aluminium", "Al", "poor_metals", 26.9815, {2,8,3,0,0,0,0}},
    {6, "Carbon", "C", "non_metals", 12.0107, {2,4,0,0,0,0,0}},
    {2, "Helium", "He", "noble_gases", 4.0026, {2,0,0,0,0,0,0}},
    {3, "Lithium", "Li", "alkali_metals", 6.941, {2,1,0,0,0,0,0}}
};



int search_mode; //stores the preferred method of search by user
int elem_number; //stores the element's atomic number entered by user
char elem_name[ELEM_NAME]; //stores the element's name entered b user
char elem_symbol[3]; //stores hte element's symbol enterd by user

//function prototypes
int find_elem_num (int num); //finds the element by its atomic number
int find_elem_name (char* str); //finds the element by its name
int find_elem_symbol (char* str); //finds element by its symbol
void print_element(int index); //prints the details of the element
    
    
int main()
{
    //prompts user for preferred method of seach mode
    printf("Welcome to the Periodic Table. Please select your preferred search mode.\n"             
          "Press\n"
          "(1) for element's atomic number\n"
          "(2) for element's name\n"
          "(3) for element's symbol\n");
    scanf("%d", &search_mode);
    
    //search based on what user selected
    switch(search_mode)
    {
        case 1:
            printf("Enter the element's atomic number: ");
            scanf("%d", &elem_number);
            print_element(find_elem_num(elem_number));
            break;
        case 2:
            printf("Enter the element's name: ");
            scanf("%s", elem_name);
            print_element(find_elem_name(elem_name));
            break;
        case 3:
            printf("Enter the element's symbol: ");
            scanf("%s", elem_symbol);
            print_element(find_elem_symbol(elem_symbol));
            break;
    }
    return 0;
}//end main()

//finds the element by its atomic number
int find_elem_num (int num)
{
    for(int i = 0; i < NUM_ELEMENTS; i++)
    {
        if (elements[i].atomic_num == num)
        {
            printf("Please find the details of the element below:\n");
            return i;
        }
    }
    printf("This element is not in the array!\n");
}

//finds the element by its name
int find_elem_name (char* str)
{
    for(int i = 0; i < NUM_ELEMENTS; i++)
    {
        if (strcmp(elements[i].name, str) == 0)
        {
            printf("Please find the details of the element below:\n");
            return i;
        }
    }
    printf("This element is not in the array!\n");
}

//finds element by its symbol
int find_elem_symbol (char* str)
{
    for(int i = 0; i < NUM_ELEMENTS; i++)
    {
        if (strcmp(elements[i].symbol, str) == 0)
        {
            printf("Please find the details of the element below:\n");
            return i;
        }
    }
    printf("This element is not in the array!\n");
}

//prints the details of the element i.e atomic number, symbol, and weight...
void print_element(int j) 
{
    int i;
    printf("%d %s %s %s %.4f",
           elements[j].atomic_num,
           elements[j].name, 
           elements[j].symbol,
           elements[j].element_class,
           elements[j].atomic_weight);
    for(i = 0; i < NUM_ELEMENTS; i++)
    {
        printf(" %d",elements[j].elec[i]);
    }
    printf("\n");
}

