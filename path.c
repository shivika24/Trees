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
void path(struct node* root)
{
    int arr[100];
       path_find(root,arr,0);

}
void path_find(struct node* root,int arr[],int l)
{
    if(root==NULL)
        return ;
    arr[l]=root->data;
    l++;
    if(root->left==NULL&&root->right==NULL)
        print(arr,l);
    else
    {
    path_find(root->left,arr,l);
    path_find(root->right,arr,l);
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    path(root);
    return 0;
}

