#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createnode(int data){
    Node* newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right= NULL;
    return newnode;
}
Node* insert(Node *root,int data){
    if(root==NULL){
        return createnode(data);
    } 
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}
void inorder(Node* root){
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
    
}
int main(){
    Node* root = NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,7);
    insert(root,2);
    insert(root,6);
    insert(root,8);
    inorder(root);
    printf("\n");
    return EXIT_SUCCESS;
}