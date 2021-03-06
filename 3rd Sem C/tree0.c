#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
    struct node* father;
}Node;
Node* newnode(char data)
{
    Node* treenode = malloc(sizeof(Node));
    treenode->data=data;
    treenode->left=NULL;
    treenode->right=NULL;
    treenode->father=NULL;
    return treenode;
}
void insert(Node** root,char data)
{
    // printf("hijibiji\n");
    if (*root == NULL)
    {
        // printf("hijibiji\n");
        *root = newnode(data); 
    }
    Node* temp = *root;
    while (temp->left!=NULL || temp->right!=NULL)
    {
        if(temp->data<data)
        {
            temp=temp->right;
        }
        else if (temp->data>data)
        {
            temp=temp->left;
        }
    }
    if(temp->data<data)
    {
        temp->right=newnode(data);
        Node* cpytmp = temp;
        temp=temp->right;
        temp->father=cpytmp;
    }
    else if (temp->data>data)
    {
        temp->left=newnode(data);
        Node* cpytmp = temp;
        temp=temp->left;
        temp->father=cpytmp;
    }
    return;
    
}
void pretrav(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    printf("%c",root->data);
    pretrav(root->left);
    pretrav(root->right);
    return;

    
}
int main()
{
    printf("hijibiji\n");
    Node* root = NULL;
    printf("hijibiji\n");
    insert(&root,'4');
    printf("hijibiji\n");
    insert(&root,'1');
    printf("hijibiji\n");
    insert(&root,'2');
    printf("hijibiji\n");
    insert(&root,'3');
    printf("hijibiji\n");
    insert(&root,'9');
    printf("hijibiji\n");
    insert(&root,'5');
    insert(&root,'6');
    insert(&root,'7');
    printf("hijibiji\n");
    pretrav(root);
    return EXIT_SUCCESS;
}