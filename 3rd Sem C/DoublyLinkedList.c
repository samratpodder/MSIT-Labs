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
    Node* temp = newnode(data);
    Node* chead = *head;
    if (*head==NULL)
    {
        *head = temp;
        return;
    }
    while(chead->next != NULL)
    {
        chead=chead->next;
    }
    chead->next=temp;
    temp->prev=chead;
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
void search(Node** list,int key){
	Node* temp = *list;
	int i=1;
	int flag = True;
	while (temp != NULL) {
		if (temp->data==key)
		{
			printf("Occurence No.:%d\tData= %d	Address= %p\n",i,temp->data,&(*temp));
			i++;
			flag=False;
		}
		temp = temp->next;
	}
	if (flag)
	{
		printf("No occurences of %d found in list at address %p\n",key,list);
	}
	
}
void reverseprint(Node** list)
{
    Node* chead = *list;
    while (chead->next!=NULL)
    {
        chead=chead->next;
    }
    while (chead!=NULL)
    {
        printf("%d",chead->data);
        chead=chead->prev;
        if(chead!=NULL){
            printf("---->");
        }
    }
    printf("\n");
}
void  delete(Node** list,int pos) 
{
	Node* temp = *list,*prev;
	if(temp==NULL){
		printf("Void List\n");
		return;
	}
		
	if(pos==1){
		*list=temp->next;
		free(temp);
		return;
	}
	while(pos>1){
		prev=temp;
		temp = temp->next;
		pos--;
	}
	prev->next=temp->next;
	free(temp);
	return;

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
			printf("%s","Enter the number to be added: ");
            int data;
            scanf("%d",&data);
            insert(&list,data);
			break;
		case 2:
			printf("Enter position to be deleted:");
			int pos;
			scanf("%d",&pos);
			delete(&list,pos);
			break;
		case 3:
			display(&list);
			break;
		case 4:
            printf("%s","Enter data to be searched: ");
            int key=0;
            scanf("%d",&key);
            search(&list,key);
		    break;
		case 5:
            reverseprint(&list);
			break;
		default:
			printf("Not a valid choice.");
			break;
		}
	}
    return EXIT_SUCCESS;
}