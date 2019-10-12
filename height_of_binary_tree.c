#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
int max(int a,int b)
{
  if(a>b)
        return a;
  else
    return b;
}
int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       return (1+max(maxDepth(node->left),maxDepth(node->right)));
   }
}
int dia(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       return 1+(dia(node->left)+dia(node->right));
   }
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of tree is %d\n", maxDepth(root));
    printf("diameter of tree is %d", dia(root));
    return 0;
}
