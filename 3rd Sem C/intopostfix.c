#include<stdio.h>
#include<stdlib.h>
#define LTR 1
#define RTL 2
typedef struct node {
	char data;
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
        printf("%c",temp->data);
        temp = temp->next;
        if (temp!=NULL)
        {
            printf("---->");
        }
        
    }
    printf("\n");
}
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
void solve(char* exp, Node** stack)
{
    Node* stk = *stack;
    while (*exp!='\0')
    {
        // printf("%c",*exp);
        if (isOperand(*exp))
        {
            printf("%c",*exp);
        }
        else
        {
            // display(*stack);
            if (*stack==NULL)
            {
                push(stack,*exp);
                // display(*stack);
                continue;
            }
            else
            {
                if (top(stack)=='(')
                {
                    push(stack,*exp);continue;
                }
                
                if (*exp=='(')
                {
                    push(stack,*exp);
                }
                if (*exp==')')
                {
                    while(top(stack)!='(')
                    {
                        printf("%c",top(stack));
                        pop(stack);
                    }
                    pop(stack);
                }
                
                if (precedence(*exp)==precedence(top(stack)))
                {
                    if (associativity(*exp)==LTR)
                    {
                        printf("%c",top(stack));
                        pop(stack);
                    }
                    if (associativity(*exp)==RTL)
                    {
                        push(stack,*exp);
                    }
                }
                if (precedence(*exp)>precedence(top(stack)))
                {
                    push(stack,*exp);
                }
                if (precedence(*exp)<precedence(top(stack)))
                {
                    while (precedence(top(stack))>=precedence(*exp))
                    {
                        printf("%c",top(stack));
                        pop(stack);
                    }
                }
                
                
                
            }
        }
        exp+=1;
    }
    // display(*stack);
    while (*stack!=NULL)
        {
            printf("%c",top(stack));
            pop(stack);
        }
}

int main()
{
    char* input = "a+(b+c*d)\0";
    Node* stack = NULL;
    solve(input,&stack);
    printf("\n");
    return EXIT_SUCCESS;
}