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

/*Insert at needs list, value and index as parameter
 *First it checks if list is empty or if inserting in first position, then we set nnode -> next to head,
 *if head was not empty we just add node in front
 * Check if tail is null too and make it point to new node
 *in other case just use a tnode to iterate through list till index position
 * If we reached tail we will append to it
 *Otherwise we will set the next and previous of current tnode to nnode and then we set the neighbor pointers to point at nnode */

void insertAt(dlist *list, int index, int val){
	Node *nnode = createnode(list, val);

	if (list->head == NULL || index == 0){
		nnode->next = list->head;
		if (list->head != NULL)
			list->head->prev = nnode;
		list->head = nnode;
		if (list->tail == NULL)
			list->tail = nnode;
		return;
	}
	Node *tnode = list->head;
	int i =0;
	while(tnode != NULL && i<index-1){

		tnode = tnode->next;
		i++;
	}
	if (tnode == list->tail){
		tnode->next = nnode;
		nnode->prev = tnode;
		list->tail = nnode;
	}else
	{
		nnode->next = tnode->next;
		nnode->prev = tnode;
		tnode->next->prev = nnode;
		tnode->next = nnode;
	}


} 

/*We check if list is empty and then return
 *Iterate through till index
 *if tnode is null return
 * if prev node was not null just unlink tnode else it is head and make it point forward
 *if tnode-> next is not null, we unlink the prev node of tnode's next  to tnode's previous
 *else if it is tail, we can set it to tnode's prev
 *free moemory for tnode once it is unlinked
  */
void deleteAt(dlist *list, int index){
	if (list->head == NULL){
	return;
	}
	Node *tnode = list->head;
	int i = 0;
	while(tnode != NULL && i<index){
		tnode = tnode->next;
		i++;
	}
	if (tnode == NULL) return;

	if (tnode->prev != NULL)
		tnode->prev->next = tnode->next;
	else
		list->head = tnode->next;
	if (tnode->next != NULL)
		tnode->next->prev = tnode->prev;
	else
		list->tail = tnode->prev;
	free(tnode);


}


int main(){
	dlist *list = createlist();
	append(list, 10);
	append(list, 20);
	append(list, 30);
	insertAt(list, 1, 15);
	deleteAt(list, 1);
	traverse(list);
	return 0;
}
