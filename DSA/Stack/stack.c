#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *arr;
	int top;
	int capacity;
} cstack;
//create stack and assign capacity, set the top
cstack* createStack(int capacity){
	cstack* s = malloc(sizeof(cstack));
	s->arr = malloc(sizeof(int) * capacity);
	s->top = -1;
	s->capacity = capacity;
	return s;
}
//To check if stack is full which is to compare top element with capacity
int isFull(cstack* s){
return s->top == s->capacity-1;
}
//To check if empty ie top element woule be -1
int isEmpty(cstack* s){
return s->top == -1;
}
//check if stack is full and if not just increment top and place element in it
void push(cstack* s, int val){
if (isFull(s)){
	printf("Stack Overflow");
	return;
}
	s->arr[++s->top] = val;
}
//check is stack is empty and if not remove the first element which is the top value
int pop(cstack* s){
	if (isEmpty(s)){
		printf("empty");
		return -1;
	}
	return s->arr[s->top--];

}
//return the top element
int peek(cstack* s){
	if (isEmpty(s)){
	return -1;
	}
	return s->arr[s->top];
}
//print stack top to bottom till empty
int print(cstack* s){
	while(!isEmpty(s))
	{
		printf("[ %d ]\n", pop(s));
	}
}

int main(){
cstack* s = createStack(4);
push(s, 1);
push(s, 2);
push(s, 3);
push(s, 4);
pop(s);
print(s);
free(s->arr);
free(s);
return 0;
}




