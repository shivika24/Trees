#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
int find(struct node* root,int elem)
{
    if(root==NULL)
        return 0;
    else if(root->data==elem)
        return 1;
    else
        return find(root->left,elem)||find(root->right,elem);
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int elem;
    scanf("%d",&elem);
    printf("%d", find(root,elem));
    return 0;
}

