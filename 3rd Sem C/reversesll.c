#include<stdio.h>
#include<stdlib.h>
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
	Node* temp = list;
	while (temp != NULL) {
		printf("Data= %d	Address= %p\n",temp->data,&(*temp));
		temp = temp->next;
	}
}
Node* top(Node** stack)
{
    int top;
    Node* temp = *stack;
    if(*stack==NULL)
    {
        return NULL;
    }
    while (temp->next!=NULL)
    {
        
        temp = temp->next;
    }
    return temp;

}
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
void show(Node* stack)
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
void reverse(Node** list)
{
    Node* temp = *list;
    Node* stack = NULL;
    while (temp!=NULL)
    {
        push(&stack,temp->data);
        temp=temp->next;
    }
    *list=NULL;
    // printf("Data in the stack:\n");
    // display(stack);
    while(top(&stack)!=NULL)
    {
        // printf("%d",top(&stack)->data);
        add(list,top(&stack)->data);
        pop(&stack);
    }
}
int main()
{
    Node* list=NULL;
    add(&list,1);
    add(&list,2);
    add(&list,3);
    add(&list,4);
    add(&list,5);
    add(&list,6);
    add(&list,7);
    printf("Original List:\n");
    display(list);
    reverse(&list);
    printf("After Reversing:\n");
    display(list);
    return EXIT_SUCCESS;
}