
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
 *To get element from an array we just check if index is in valid range
 *If valid we just return pointer to that index of array which has the value
*/

int get(DynamicArray *arr, int index)
{
	if (index<0 || index > arr->size){
		printf("Illegal Index");
	return -1;
	}
	return arr->data[index];
}

/*
 * To Update we take position and value to be entered as parameters
 * We check if index is in valid range
 * if yes just assign the pointer to the new value
 * */
void update(DynamicArray *arr, int val, int index){
	if (index < 0 || index > arr->size){
		printf("Illegal Operation");
	return;}
	arr->data[index] = val;
}

/*
 * To Remove an element we just need the index position as parameter
 * Again check if index is in valid range
 * If yes shift all element to left using i+1
 * Decrease size by 1 to keep the value updated
 */
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



int main(){
	DynamicArray *arr = createArray(2);
	append(arr, 1);
	append(arr, 2);
	append(arr, 3);
	int x = get(arr, 2);
	printf("Got: %d \n", x);
	update(arr, 5, 2);
	removeA(arr, 0);
	printf("Final Array: ");
	for (int i = 0; i < arr->size; i++){
	 printf("%d ", arr->data[i]);
	}
	printf("\n");
	freeArray(arr);
	return 0;
}


