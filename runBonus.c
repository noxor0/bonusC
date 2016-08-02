#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate10(int **x){
	int *y = malloc(sizeof(int) * 20);
	int i;
	for(i=0;i<10;i++) {
		y[i] = i;
	}
	*x = y;
}

void joinStrings(char *str1, char *str2, char **str3) {
	int str1_len, str2_len, str3_len;
	char *finalstr;
	str1_len = strlen(str1);
	str2_len = strlen(str2);
	str3_len = str1_len + str2_len;
	finalstr = malloc(sizeof(char) * str3_len + 1);
	strcpy(finalstr, str1);
	strcat(finalstr, str2);
	*str3 = finalstr;
}

void arrayWrite(int arr[4][3], int sizeOfArr, char *binaryFilename) {
	int i;
	int j;
	char* line = malloc(9);
	FILE *fp;
	fp = fopen(binaryFilename, "wb");
	for(i = 0; i < sizeOfArr - 1; i++) {
		if (i == (sizeOfArr - 2)) {
			for(j = 0; j < 2; j++) {
				sprintf(line, "%d", arr[i][j]);
				fwrite(line, sizeof(char), 1, fp);
			}
		} else {
			for(j = 0; j < 3; j++) {
				sprintf(line, "%d", arr[i][j]);
				fwrite(line, sizeof(char), 1, fp);
			}
		}
	}
	printf("done\n");
	free(line);
	fclose(fp);
}

//run with parameter e? why?
void binaryIO(char *file1, char *file2) {
	FILE *fp1, *fp2;
	fp1 = fopen(file1, "rb");
	//want this one in binary too? unclear
	fp2 = fopen(file2, "w");
	char *line = malloc(2 * sizeof(int) + 2);
	char *line2 = malloc(sizeof(int) + 1);
	int numb;
	while(fread(line,sizeof(char),1,fp1)){
		sscanf(line, "%d", &numb);
		line[1] = ',';
		line[2] = '\0';
		numb = numb * numb;
		sprintf(line2, "%d\n", numb);
		strcat(line, line2);
		fwrite(line, strlen(line), 1, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	free(line);
	free(line2);
	puts("done");
}

void arrayCopy(int ***theFArray, int ***theGArray, int theEArray[][3], int theSizes[2]) {
     int rows = theSizes[0];
     int col = theSizes[1];

     int size = rows * col * sizeof(int);
     *theFArray = malloc(size);
     *theGArray = malloc(size);

     memcpy(*theFArray, &theEArray, size);
     memcpy(*theGArray, &theEArray, size);
 }

int main(){
	int *a;
	char *b="Hello ";
	char *c="World";
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

	allocate10(&a);
	int i;
	for (i = 0; i < 10; i++){
		printf("number: %d\n", a[i]);
	}
	free(a);

	allocate10(&a);
	fprintf(stdout, "number: %d\n", a[8]);

	//*******************************************************
	//1 mark
	//Write a function "joinStrings" takes as parameters 3 strings. It joins the first 2 together and puts the result in the third string
	//The function allocates memory for the third string using malloc
	//apply the function to strings b,c, and d. After the function is done d should have memory allocated to it and contain "Hello World"
	//the function should not assume the sizes of b or c - it needs to be general enough for any string
	//after calling the function using b,c,d as parameters print out d from the main function
	//free the memory in d
	//*******************************************************
	printf("--------\n");
	joinStrings(b, c, &d);
	printf("%s\n", d);
	free(d);

	//*******************************************************
	//1 mark
	//write a function "arrayWrite" that takes as parameters an array of the same type as e, the size of the first dimension, and a string variables, binaryFilename
	//the function "arrayWrite" writes the values of the the array (starting from array[0][0] and ending at array[size-1][2]) to the binaryFilename
	//apply the function to array e and file1
	//*******************************************************
	printf("--------\n");
	size = 4;
	arrayWrite(e, size, file1);

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
	printf("--------\n");
	binaryIO(file1, file2);
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
	printf("--------\n");
	sizes[0] = 4;
	sizes[1] = 3;
	arrayCopy(&f, &g, e, sizes);
	printf("%s", "f:");
	for (i = 0; i < 12; i++){
		printf("%d ", *((*f)+i));
	}
	printf("\n%s", "g:");
	for (i = 0; i < 12; i++){
		printf("%d ", *((*g)+i));
	}
	printf("\n");
	return 1;
}
