#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node;
Node* add(Node* list,int data) {
	/*while (list->next != NULL) {
		list = list->next;
	}*/
	list->data = data;
	list->next = malloc(sizeof(Node*));
	list = list->next;
	list->data = -999;
	list->next = NULL;
	return list;
}
void display(Node* list){
	while (list->next != NULL) {
		printf("Data= %d	Address= %p\n",list->data,&(*list));
		list = list->next;
	}
}
void insert_inbetween(Node* list,int data) {
	int counter = 0;
	Node* head = list;
	while (list->next != NULL) {
		counter += 1;
		list = list->next;
	}
	int mid = counter / 2;
	Node* newnode = malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	while (mid != 1)
	{
		head = head->next;
		mid--;
	}
	newnode->next = head->next;
	head->next = newnode;
}
int  delete() {
	return 0;
}
int main123() {
	Node* list = malloc(sizeof(Node));
	Node* head = list;
	//list->data = 0;
	//list->next = malloc(sizeof(Node*));
	//printf("Data= %d\tAddress= %p\n", list->data, &list);
	//list = list->next;
	//list->next = NULL;
	//list->data = 1;
	//list->next = malloc(sizeof(Node*));
	//printf("Data= %d\tAddress= %p\n", list->data, &list);
	//list = list->next;
	
	//list->data = 2;
	//list->next = NULL;
	//printf("Data--->%d\tAddress--->%p",list->data,&list);

	list = add(list,1);
	list = add(list, 2);
	list = add(list, 3);
	list = add(list, 4);
	/*list = add(list, 6);
	list = add(list, 7);
	list = add(list, 8);
	list = add(list, 9);
	list = add(list, 0);*/
	insert_inbetween(head,5);

	display(head);
	//traverse(head);
	//free(list);
	return EXIT_SUCCESS;
}