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
    // 
    if (*root == NULL)
    {
        // 
        *root = newnode(data); 
    }
    Node* temp = *root;
    int done =0;
    while (!done)
    {
        if(data<temp->data && temp->left!=NULL)
        {
            temp=temp->left;continue;
        }
        else if (data>temp->data && temp->right!=NULL)
        {
            temp=temp->right;continue;
        }
        done=1;
    }
    /*
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
    }*/
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
void intrav(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    intrav(root->left);
    printf("%c",root->data);
    intrav(root->right);
    return;

    
}
void posttrav(Node* root)
{
    if (root==NULL)
    {
        return;
    }
    posttrav(root->left);
    posttrav(root->right);
    printf("%c",root->data);
    
}
int main()
{
    Node* root = NULL;
    insert(&root,'4');
    insert(&root,'1');
    insert(&root,'2');
    insert(&root,'3');
    insert(&root,'9');
    insert(&root,'5');
    insert(&root,'6');
    insert(&root,'7');
    printf("\nPreorder:");
    pretrav(root);
    printf("\nInorder:");
    intrav(root);
    printf("\nPostorder:");
    posttrav(root);
    printf("\n");
    return EXIT_SUCCESS;
}