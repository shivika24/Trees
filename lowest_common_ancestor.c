#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}treenode;

treenode* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
/*int find(treenode* root,int elem)
{
    if(root==NULL)
        return 0;
    else if(root->data==elem)
        return 1;
    else
        return find(root->left,elem)||find(root->right,elem);
}*/
 treenode* LCA(treenode* root, int B, int C) {
     if(root==NULL)
     return NULL;
     if(root->data==B||root->data==C)
     return root;
     treenode* x=LCA(root->left,B,C);
     treenode* y=LCA(root->right,B,C);
     if(x&&y)
     return root;
     else if(x)
     return x;
     else if(y)
     return y;
     else
     return NULL;

}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    treenode* res=LCA(root,2,3);
    printf("%d",res->data);
    return 0;
}


