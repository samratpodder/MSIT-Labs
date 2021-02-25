typedef struct node {
	int data;
	struct node* next;
}Node;
void add(Node** list,int data);
void reverseprint(Node* head);
void display(Node* list);
void delete(Node** list,int pos);
void search(Node** list,int key);

