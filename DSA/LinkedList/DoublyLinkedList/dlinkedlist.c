#include<stdio.h>
#include<stdlib.h>


/*Creating structures for node and soubly linked list
 *Node consist of data, pointer to next and previous node
 *dlist consist of head and tail, head is first node and tail is the last
 */
typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} dlist;


/*create node just needs list and value to be added as parameter
 *Allocate enough memory to hold node
 *set the data of node to value and set next and prev nodes as NULL since it is yet to be added in list
 */
Node* createnode(dlist *list, int val){
	Node *nnode = (Node*)malloc(sizeof(Node));
        nnode->data = val;
	nnode->next = NULL;
	nnode->prev = NULL;
	return nnode;
}


/*creating list is just allocating enough memory
 *set list head to null as there is no node yet
 *set list tail to null
 */
dlist* createlist(){
	dlist *list = (dlist*)malloc(sizeof(dlist));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

/*append takes node value and list as parameter
 *First create the node and then check if list is empty
 *if empty insert the node and set list head and tail to new node
 *if not empty add node to tail->next, set previous to list->tail(previous node)
 *lastly update list->tail to new node as to update the last element
 */
void append(dlist *list, int val){
	Node *nnode = createnode(list, val);
	if(list->head == NULL){
		list->head = nnode;
		list->tail = nnode;
		return;
}
	list->tail->next = nnode;
	nnode->prev = list->tail;
	list->tail = nnode;
}

/*traversing takes list as parameter, make a tnode pointer and iterate through whole list until node is pointing to NULL
 *Print the curr tnode value in every iteration
 *increment to next
 */

void traverse(dlist *list){
	Node *tnode = list->head;
	while(tnode != NULL)
	{
		printf("%d<->", tnode->data);
		tnode = tnode->next;
	}
	printf("NULL\n");
}



int main(){
	dlist *list = createlist();
	append(list, 10);
	append(list, 20);
	append(list, 30);
	traverse(list);
	return 0;
}
