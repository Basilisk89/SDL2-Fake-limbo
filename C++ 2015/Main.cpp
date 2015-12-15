//# predefined compiler operatives
//<> go to where the includes are
#include <stdio.h>
#include <stdlib.h>
//defines LENGTH as 1024
//#define LENGTH 1024
// old Main call
// int args
// char *argv[] i would like the pointer/address to the argv character array
int main(int args, char *argv[]) {
	// Stack Variable of arrays
	// pointer to an integer for the array
	const int LENGTH = 1024;
	int array[LENGTH];
	// prints hello world to the console

	// for loop to loop through our array of 1024
	for (int i = 0; i < LENGTH; i++) {
		//%d/ prints to decemals values
		//lets print the array of information thats already there
		//and initiallize our int* array value
		array[i] = 0;
		printf("%d\n", array[i]);// prints out the addresses of the array
	}
	//putting array address into type void *
	// void *ptr = array;
	// made array into a char* and put the array into the char* ptr value
	//char *ptr = (char*)array;
	//returning the 512th element of the array and returns the address and put it into a float pointer called ptr
	float *ptr = (float*)&array[512];
	//%x sets our print to hex values
	// prints out the hex value of array and the 0th and 1st part of the first array
	// the name of the array is the address
	// this is digging up the first part of the stack
	// array[0] is the first index of the array also offset of that address
	// & returns the address of the zeroeth element
	//int * is 4 bytes
	//int is 4 bytes
	//char is 1 byte
	//to look for a char requires for 4 bytes
	//char * is 4
	//short is 4
	//float is 4
	//double is 8
	//double * is 4 bytes
	// POINTERS ARE 4 bytes
	//unsigned longs are 4 bytes and that is what a pointer is.
	printf("%x  %x %X\n", sizeof(long), &array[0], ptr + 1);

	// press any key call
	printf("Hello World!\n");
	getchar();
	return 0;
}