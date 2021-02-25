#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
typedef struct node {
	int data;
    struct node* prev;
    struct node* next;
}Node;
Node* newnode(int data)
{
    Node* newnode = malloc(sizeof(Node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
void insert(Node** head,int data)
{
    Node* chead = *head;
    Node* temp = newnode(data);
    if (head==NULL)
    {
        chead = temp;
        return;
    }
    while (chead->next!=NULL)
    {
        chead=chead->next;
    }
    chead->next=temp;
    temp->prev=chead;
    temp->next=NULL;
    return;
}
void display(Node** head)
{
    Node* temp = *head;
    while(temp!= NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
        if (temp!=NULL)
        {
            printf("---->");
        }
        
    }
    printf("\n");
    
}
int main()
{
    int input=999;
	Node* list = NULL;
	while(input!=0){
		printf("Enter 1 to add\n");
		printf("Enter 2 to delete\n");
		printf("Enter 3 to display\n");
		printf("Enter 4 to search\n");
		printf("Enter 5 to reverse print.\n");
		printf("Enter 0 to exit.\n");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("%s","Enter the number to be added");
            int data;
            scanf("%d",&data);
            insert(&list,data);
			break;
		case 2:
			
			break;
		case 3:
			display(&list);
			break;
		case 4:
		    break;
		case 5:
			
			break;
		default:
			printf("Not a valid choice.");
			break;
		}
	}
    return EXIT_SUCCESS;
}