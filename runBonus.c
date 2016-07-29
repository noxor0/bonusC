#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate10(int **x){
		*x = malloc(sizeof(int) * 10);
		printf("The size: %zu\n", sizeof(*x));
		int i;
		for (i = 0; i < 10; i ++) {
			x[i] = 0;
		}
		fprintf(stdout, "%d\n", sum);
	}

int main(){
	int *a;
	char *b="Hello ";
	char *c= "World";
	char *d;
	char *file1="e.bin";
	char *file2="e.txt";
	int size;
	int sizes[2];
	int e[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int **f;
	int **g;
	
	//*******************************************************
	//1 mark
	//write a function "allocate10" that allocates space for 10 integer using the parameter list
	//in other words the function is of VOID type, takes a parameter and allocates and assigns memory to that parameter
	//call the function to allocate and assign memory to a
	//use a loop in the function to assign a[0] to a[9] to integers 0 to 9 
	//print the values out one per line in the main program
	//To be clear - the memory is allocated and assigning values happens in the function
	//in the main function
	//free the memory in 
	//*******************************************************
	printf("The size: %zu\n", sizeof(*a));
	allocate10(&a);
	printf("The size: %zu\n", sizeof(*a));

	//*******************************************************
	//1 mark 
	//Write a function "joinStrings" takes as parameters 3 strings. It joins the first 2 together and puts the result in the third string
	//The function allocates memory for the third string using malloc
	//apply the function to strings b,c, and d. After the function is done d should have memory allocated to it and contain "Hello World"
	//the function should not assume the sizes of b or c - it needs to be general enough for any string
	//after calling the function using b,c,d as parameters print out d from the main function
	//free the memory in d
	//*******************************************************

	//*******************************************************
	//1 mark
	//write a function "arrayWrite" that takes as parameters an array of the same type as e, the size of the first dimension, and a string variables, binaryFilename
	//the function "arrayWrite" writes the values of the the array (starting from array[0][0] and ending at array[size-1][2]) to the binaryFilename
	//apply the function to array e and file1
	//*******************************************************


	//******************************************************* 
	//1 mark
	//write a function "binaryIO" to take as a parameter two filenames
	//it opens the first file which is binary reads in sizeof(int) bytes at a time
	//it writes value and the value squared separated by a ',' one set of values per line i.e.
	//0,0
	//1,1
	//2,4 
	//etc. to a the second file
	//
	//run the function with parameters e,file1, file2
	//so at the end of this there should be two new files
	//*******************************************************

	//******************************************************* 
	//2 marks
	//malloc and assign memory for	f as a pointer to pointers to integer style array of the same size as e
	//malloc and assign memory for g as a pointer to pointer to integer where you assign the pointers to a block of memory the size of e
	//write a function "arrayCopy" that that takes parameters of the same type as e, f, and g and a sizes array parameter
	//sizes is an array of the dimension sizes
	//use for loops to copy values of e to f and g inside the function
	//in main print out e, f and g
	//in main free the memory for f
	//in main free the memory for g
	//*******************************************************
	 
	return 1;
}

