#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node;
void push(Node** stack,int data)
{
    Node* top = *stack;
    Node* newnode = malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    if (top==NULL)
    {
        *stack = newnode;
        return;
    }
    
    while (top->next!=NULL)
    {
        top=top->next;
        // printf("%d",top->data);
    }
    top->next=newnode;
    // printf("%d",newnode->data);
    return;
}
void display(Node* stack)
{
    Node* temp=stack;
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
void pop(Node** stack)
{
    Node* top = *stack,*prev;
    if(*stack==NULL)
    {
        return;
    }
    if(top->next == NULL)
    {
        *stack=NULL;
        free(top);
        return;
    }
    while (top->next!=NULL)
    {
        prev=top;
        top=top->next;
        // printf("%d",top->data);
    }
    prev->next=NULL;
    free(top);
}
int main()
{
    int input=999;
	Node* stack = NULL;
	while(input!=0){
		printf("Enter 1 to push\n");
		printf("Enter 2 to pop\n");
		printf("Enter 3 to display\n");
		printf("Enter 0 to exit.\n");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("Enter data to be pushed:");
			int data;
			scanf("%d",&data);
			push(&stack,data);
			break;
		case 2:
			pop(&stack);
			break;
		case 3:
			display(stack);
			break;
		default:
			printf("Not a valid choice.");
			break;
		}
	}
    return EXIT_SUCCESS;
}