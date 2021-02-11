#include<stdio.h>
#include<stdlib.h>
#define LTR 1
#define RTL 2
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
int top(Node** stack)
{
    int top;
    Node* temp = *stack;
    while (temp->next!=NULL)
    {
        temp = temp->next;
        top=temp->data;
    }
    return top;
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
int precedence(char c) 
{ 
    switch (c) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 
int associativity(char c)
{
    switch (c)
    {
    case '^':
        return RTL;
    case '+':
    case '-':
    case '*':
    case '/':
        return LTR;
    default:
        return -1;
        break;
    }
}
int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') ||  
           (ch >= 'A' && ch <= 'Z'); 
} 
int main()
{
    char* input = "a+b*(c^d-e)^(f+g*h)-i";
    Node* stack = NULL;
    
    return EXIT_SUCCESS;
}