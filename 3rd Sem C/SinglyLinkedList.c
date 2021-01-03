#include<stdio.h>
#include<stdlib.h>
#define True 1
typedef struct node {
	int data;
	struct node* next;
}Node;

void add(Node** list,int data) {
	/*while (list->next != NULL) {
		list = list->next;
	}*/
	Node* newnode=malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	if (*list==NULL)
	{
		*list=newnode;
		//printf("NULL:Data= %d	Address= %p\n",(*list)->data,&(**list));
		return;
	}
	Node* temp=*list;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	//printf("Data= %d	Address= %p\n",newnode->data,&newnode);
	return;
	
	// list->data = data;
	// list->next = malloc(sizeof(Node*));
	// list = list->next;
	// list->data = -999;
	// list->next = NULL;
}

void display(Node* list){

	while (list != NULL) {
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
int main() {
	int input=999;
	Node* list = NULL;
	while(input!=0){
		printf("Enter 1 to add\n");
		printf("Enter 2 to delete\n");
		printf("Enter 3 to display\n");
		printf("Enter 0 to exit.\n");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("Enter data and position to be appended:");
			int data;
			scanf("%d",&data);
			add(&list,data);
			break;
		case 2:
			printf("Enter position to be deleted:");
			int pos;
			scanf("%d",&pos);

			break;
		case 3:
			display(list);
			break;
		default:
			printf("Not a valid choice.");
			break;
		}
	}
	
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

	// list = add(list,1);
	// list = add(list, 2);
	// list = add(list, 3);
	// list = add(list, 4);
	// /*list = add(list, 6);
	// list = add(list, 7);
	// list = add(list, 8);
	// list = add(list, 9);
	// list = add(list, 0);*/
	// insert_inbetween(head,5);

	// display(head);
	//traverse(head);
	//free(list);
	return EXIT_SUCCESS;
}