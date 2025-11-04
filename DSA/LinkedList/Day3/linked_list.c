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

/*Take target value and list as parameters for the functioon
 * use pointer tnode and start from head of the list till tnode data is equal to value 
 *once found print the index at which target is seen, keep track of it using i variable
*/
int search(linkedlist* list, int val){
	Node* tnode = list->head;
	int i = 0;
	while(tnode->data != val){
	tnode = tnode->next;
	i++;
	}
	printf("Exists at %d\n",i);
}

/*need 3 pointters for prev current and next
 *till current node is not null we iterate 
 *in each iteration, first we temporarily store the next node in next pointer, then we use the curr pointer to point to previous
 *then just update prev with current and then current back to where the next was pointed         
 * Lastly set the head to prev which was the last element 
*/

void reverse(linkedlist* list){
	Node* prev = NULL;
	Node* curr = list->head;
	Node* next = NULL;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

	}
	list->head = prev;
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
	search(list, 10);
	reverse(list);
	traverse(list);
	return 0;
}
