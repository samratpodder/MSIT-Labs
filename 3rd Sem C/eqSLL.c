#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
typedef struct node {
	int data,exp;
	struct node* next;
}Node;
void add(Node** list,int data,int exp) {
	/*while (list->next != NULL) {
		list = list->next;
	}*/
	Node* newnode=malloc(sizeof(Node));
	newnode->data=data;
    newnode->exp=exp;
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
	Node* temp = list;
	while (temp != NULL) {
		printf("%dx^%d",temp->data,temp->exp);
		temp = temp->next;
        if(temp!=NULL){
            printf("+");
        }
        else
        {
            printf("\n");
        }
        
	}
}
int main() {
	int input=999;
	Node* list = NULL;
	while(input!=0){
		printf("Enter 1 to add\n");
		printf("Enter 2 to display\n");
		printf("Enter 0 to exit.\n");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("Enter data and exponent:");
			int data,exp;
			scanf("%d %d",&data,&exp);
			add(&list,data,exp);
			break;
		case 2:
			display(list);
			break;
		default:
			printf("Not a valid choice.");
			break;
		}
	}
	return EXIT_SUCCESS;
}