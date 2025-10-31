
#include <stdio.h>  //Library to use printf
#include <stdlib.h> //Library to use malloc, free

/* definig  a structure that takes a pointer, size, capacity which is basically everything you need for an array; structure is named as DynamicArray */
typedef struct {
	int *data;
	int size;
	int capacity;
} DynamicArray;

/* Declaring Function createArray which takes integer capacity value
 * Allocate enough space which is DynamicArray worth and arr will be having address to thtat structure
 * allocating memory to hold the needed capacity
 * size is 0 by default because no elements
 * capacity is the value given
 * return the arr variable on stack that holds address to the structure DynamicArray we created */
DynamicArray* createArray(int capacity){
	DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
	arr->data = (int*)malloc(capacity * sizeof(int));
	arr->size = 0;
	arr->capacity = capacity;
	return arr;
	}

/*Create free function to free memory; in general a good practice */
void freeArray(DynamicArray *arr){
free(arr->data);
free(arr);
}

/*check if size exceeds capacity
 * if yes reallocate memory and assign pointer as well as update capacity value
 * Check for memory issues as new location allocation can make you curent pointer invalid
 *Update size and put value into the referenced address of array*/
void append(DynamicArray *arr, int val){
	if (arr->size == arr->capacity){
		arr->capacity*=2;
		arr->data = realloc(arr->data, arr->capacity * sizeof(int));
		if(arr->data == NULL)
		{
			printf("Reallocation Failed\n");
			exit(1);
		}
		printf("Resized to %d\n", arr->capacity);
	}
	arr->data[arr->size] = val;
	arr->size++;
	}

/* initializing the array, calling function createArray and printing values
 * free the memory*/
int main(){
DynamicArray *arr = createArray(2);

for (int i=0; i<=10; i++)
{
	append(arr, i);
}

freeArray(arr);
return 0;

}
