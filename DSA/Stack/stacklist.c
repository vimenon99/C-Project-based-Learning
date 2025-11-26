#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	struct Node* next;
	int data;
}Node;

typedef struct{
	Node* top;
}lstack;

lstack* createStack(){
	lstack* s = (lstack*)malloc(sizeof(lstack));
	s->top = NULL;
}

void push(lstack* s, int val){
	Node* nnode = (Node*)malloc(sizeof(Node*));
	nnode->next = s->top;
	nnode->data = val;
	s->top = nnode;
}

int pop(lstack* s){
	Node* tmp = s->top;
	int val = tmp->data;
	s->top = s->top->next;
	free(tmp);
	return val;
}

int main(){
 lstack* s = createStack();
 push(s, 1);
 push(s, 2);
 push(s, 3);
 pop(s);
 while(s->top != NULL){
	 printf("%d\n",pop(s));
 }
 free(s);
 return 0;
}

