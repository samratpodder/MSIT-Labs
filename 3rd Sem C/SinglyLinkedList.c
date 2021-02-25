#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
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
void reverseprint(Node* head)
{
	if (head == NULL)
	{
		return;
	}
	reverseprint(head->next);
	printf("%d\t",head->data);
	return;
}
void display(Node* list){
	Node* temp = list;
	while (temp != NULL) {
		printf("Data= %d	Address= %p\n",temp->data,&(*temp));
		temp = temp->next;
	}
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
int main() {
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
			printf("Enter data and position to be appended:");
			int data;
			scanf("%d",&data);
			add(&list,data);
			break;
		case 2:
			printf("Enter position to be deleted:");
			int pos;
			scanf("%d",&pos);
			delete(&list,pos);
			break;
		case 3:
			display(list);
			break;
		case 4:
		printf("Enter data to be searched: ");
		int searchdata;
		scanf("%d",&searchdata);
			search(&list,searchdata);break;
		case 5:
			reverseprint(list);
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