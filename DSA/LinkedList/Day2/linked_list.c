#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

typedef struct{
	Node* head;
} linkedlist;

linkedlist* createlist(){
	linkedlist* list = (linkedlist*)malloc(sizeof(linkedlist));
	list->head = NULL;
	return list;
}

Node* createnode(int val){
	Node* nnode = (Node*)malloc(sizeof(Node));
	nnode->data = val;
	nnode->next = NULL;
	return nnode;

}

void append(linkedlist* list, int val){
	Node* nnode = createnode(val);
	if (list->head == NULL){
		list->head = nnode;
		return;
	}
	Node* tnode = list->head;
	while(tnode->next != NULL){
		tnode = tnode->next;

	}
	tnode->next = nnode;
}

void traverse(linkedlist* list){
	Node* tnode = list->head;
	while(tnode!=NULL){
	printf("%d -> ", tnode->data);
	tnode = tnode->next;
	}
	printf("NULL\n");
}

/*Prepend needs to take list and val as parameters
 * create a node and setnew node's next to list's head which is node 1
 * set the head node to point to nnode
*/
void prepend(linkedlist* list, int val){
	Node* nnode = createnode(val);
	nnode->next = list->head;
	list->head = nnode;
}

/* count i for 1 index before the target
 * iterate till the -1 position from target
 * just switch the pointers next to newly created node
*/
void insertAt(linkedlist* list, int index, int val){
	int i = 0;
	Node* tnode = list->head;
	while(i<index-1){
	tnode = tnode->next;
	i++;
	}
	Node* nnode = createnode(val);
	nnode->next = tnode->next;
	tnode->next = nnode;
	

}
/*
 *iterate with tnode and stop just before the target
 *create a new temp pointer variable that points to target's next node
 * Lastly update current tnode;s next with cnodes's next which is target's next
 *Delete the cnode and free memory 
 */


void deleteAt(linkedlist* list, int index){
int i = 0;
Node* tnode = list->head;
while(i<index-1)
{
	tnode = tnode->next;
	i++;
}

    Node* cnode = tnode->next;
    tnode->next = cnode->next;
    free(cnode);
}

int main(){
	linkedlist* list = createlist();
	append(list, 10);
	append(list, 20);
	append(list, 30);
	prepend(list, 0);
	insertAt(list, 2, 15);
	deleteAt(list,3);
	traverse(list);
	return 0;
}
