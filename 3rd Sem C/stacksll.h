typedef struct node {
	int data;
	struct node* next;
}Node;
int top(Node** stack);
void push(Node** stack,int data);
void show(Node* stack);
void pop(Node** stack);