#include<stdio.h>
#include<stdlib.h>
struct node{
    int data:
    struct node* left;
    struct node* right;
};
struct node * createnewnode(int value){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left= NULL;
    newnode->right=NULL;
    return newnode;
}
if(value> root->right)
    root->right = insert(root->right, value);
else
    root->left =insert(root->left, value);
return root;

void inorder(struct node * root){
    if(root){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}