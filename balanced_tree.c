 #include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}treenode;

treenode* newNode(int data)
{
    treenode* node = (treenode*)malloc(sizeof(treenode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
 int max(int a,int b)
{
  if(a>b)
        return a;
  else
    return b;
}
int maxDepth(treenode* node)
{
   if (node==NULL)
       return 0;
   else
   {
       return (1+max(maxDepth(node->left),maxDepth(node->right)));
   }
}
int isBalanced(treenode* node) {
    int r,l;
 if (node==NULL)
       return 1;
       r=maxDepth(node->right);
       l=maxDepth(node->left);
      if (abs(l - r) <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return 1;
  return 0;
}
int main()
{
    treenode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("%d", isBalanced(root));
    return 0;
}
