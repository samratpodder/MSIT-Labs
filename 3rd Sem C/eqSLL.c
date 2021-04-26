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
		if (temp->data=0)
		{
			continue;
		}
		
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
Node* sum(Node** list1,Node** list2,Node* res)
{
	
	Node* temp1 = *list1;
	Node* temp2 = *list2;
	while (temp1->next!=NULL)
	{
		Node* newnode=malloc(sizeof(Node));
		newnode->data=(temp1->data)+(temp2->data);
    	newnode->exp=temp1->exp;
		newnode->next=NULL;
		if (res==NULL)
		{
			res=newnode;
			continue;
		}
		while(res->next!=NULL)
		{
			res=res->next;
		}
		res->next=newnode;
		
	}
	return res;
	
}
int main() {
	int input=999;
	Node* list1 = NULL;
	Node* list2 = NULL;
	Node* result=NULL;
	while(input!=0){
		printf("Enter 1 to create\n");
		printf("Enter 2 to display\n");
		printf("Enter 3 to add two lists\n");
		printf("Enter 0 to exit.\n");
		scanf("%d",&input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("List 1:\n");
			printf("Enter highest order:");
			int data,exp;
			scanf("%d",&exp);
			for (int i = exp; i >=0  ; i--)
			{
				printf("Coefficient of x^%d: ",i);
				scanf("%d",&data);
				add(&list1,data,exp);
			}
			printf("List 2:\n");
			printf("Enter highest order:");
			int data2,exp2;
			scanf("%d",&exp2);
			for (int i = exp2; i >=0  ; i--)
			{
				printf("Coefficient of x^%d: ",i);
				scanf("%d",&data2);
				add(&list2,data,exp);
			}
			break;
		case 2:
			display(list1);
			display(list2);
			display(result);
			break;
		case 3:
			result=sum(&list1,&list2,result);
			display(result);
		default:
			printf("Not a valid choice.");
			break;
		}
	}
	return EXIT_SUCCESS;
}