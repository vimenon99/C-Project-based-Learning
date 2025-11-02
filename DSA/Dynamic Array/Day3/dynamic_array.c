
#include <stdio.h>  //Library to use printf
#include <stdlib.h> //Library to use malloc, free

typedef struct {
	int *data;
	int size;
	int capacity;
} DynamicArray;

DynamicArray* createArray(int capacity){
	DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
	arr->data = (int*)malloc(capacity * sizeof(int));
	arr->size = 0;
	arr->capacity = capacity;
	return arr;
}

void append(DynamicArray *arr, int val)
{
	if (arr->size == arr->capacity)
	{
		arr->capacity*=2;
		arr->data = realloc(arr->data, arr->capacity * sizeof(int));
		if (arr->data == NULL){
			printf("Reallocation Failed");
			exit(1);
		}}
		arr->data[arr->size] = val;
		arr->size++;
	}
void freeArray(DynamicArray *arr){
	free(arr->data);
	free(arr);
}

/*
 * Taking the value to be inserted and position(index) as parameters
 * check if index is in valid range and if size equals capacity of array
 * if size has reached capacity make room just like in append and make sure pointer for data doesn't point to NULL
 * Run a full loop from last element of array till index and shift the elements to right by iterating left
 * update index value which is target and increment the size as new element has been added
 */
void insertAt(DynamicArray *arr, int val, int index){
	if (index < 0 || index > arr->size){
	printf("Operation Failed");
	return;}
	
	if (arr->size == arr->capacity){
	arr->capacity*=2;
	arr->data = realloc(arr->data, arr->capacity * sizeof(int));
		if (arr->data == NULL){
			exit(1);
}	
}
	
	for (int i = arr->size -1; i >= index; i --)
	{
		arr->data[i+1] = arr->data[i];
	}
	arr->data[index] = val;
	arr->size++;
}


int get(DynamicArray *arr, int index)
{
	if (index<0 || index > arr->size){
		printf("Illegal Index");
	return -1;
	}
	return arr->data[index];
}


void update(DynamicArray *arr, int val, int index){
	if (index < 0 || index > arr->size){
		printf("Illegal Operation");
	return;}
	arr->data[index] = val;
}


void removeA(DynamicArray *arr, int index){
	if(index < 0 || index > arr->size){
		printf("Illegal Operation");
		return;
	}
	for(int i = index; i < arr->size; i++)
	{
		arr->data[i] = arr->data[i + 1];

	}
	arr->size--;
}

/*
 *Linear search is just a simple search for any passed value it fetches the index of the element
*Typically search starts from the first element and goes on till we find the element
*/

int lSearch(DynamicArray *arr, int val)
{
	for (int i=0; i < arr->size; i++)
	{
		if (arr->data[i] == val){
		return i;
		}
	}
	return -1;
}


int main(){
	DynamicArray *arr = createArray(2);
	append(arr, 1);
	append(arr, 2);
	append(arr, 3);
	int x = get(arr, 2);
	printf("Got: %d \n", x);
	update(arr, 5, 2);
	removeA(arr, 0);
	insertAt(arr, 1, 1);
	insertAt(arr, 0, 0);
	printf("Final Array: ");
	for (int i = 0; i < arr->size; i++){
	 printf("%d ", arr->data[i]);
	}
	printf("\n");
	int g = lSearch(arr, 2);
	printf("%d \n", g);
	freeArray(arr);
	return 0;
}


