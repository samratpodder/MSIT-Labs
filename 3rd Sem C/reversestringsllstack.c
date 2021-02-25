#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	char data;
	struct node* next;
}Node;
char top(Node** stack)
{
    char top;
    Node* temp = *stack;
    while (temp->next!=NULL)
    {
        
        temp = temp->next;
        top=temp->data;
    }
    return top;

}
void push(Node** stack,char data)
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
        printf("%c",temp->data);
        temp = temp->next;
        // if (temp!=NULL)
        // {
        //     printf("---->");
        // }
        
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

void reverse(Node* list)
{
    if(list==NULL)
    {
        return;
    }
    reverse(list->next);
    printf("%c",list->data);
    return;
}
int main()
{
    Node* list=NULL;
    char* str = "This String will be reversed!\0";
    while (*str!='\0')
    {
        // printf("%c",*str);
        push(&list,*str);
        str+=1;
    }
    show(list);
    // show(list);
    reverse(list);
    return EXIT_SUCCESS;
}