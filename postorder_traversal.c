#include<stdio.h>
typedef struct Treenode
{
    int data;
    struct Treenode* left;
    struct Treenode* right;
}treenode;
typedef struct stack
{
    treenode* data;
    struct stack* next;
}stack;
void push(stack **head,treenode *add)
{
    stack* newNode=(stack *)malloc(sizeof(stack));
    if(newNode==NULL)
    {
        printf("stack is full");
    }
    else
    {
        newNode->data=add;
        newNode->next=(*head);
        *head=newNode;
    }
}
treenode* pop(stack **head)
{
   stack* temp=(*head);
   treenode *node=NULL;
   node=temp->data;
   *head=temp->next;
   free(temp);
   return node;
}
treenode* peek(stack *head)
{
    if(head==NULL)
        return NULL;
    else
        return head->data;
}
int isEmpty(stack *head)
{
    if(head==NULL)
        return 1;
    else
        return 0;
}
struct node* newNode(int data)
{
    treenode* node = (struct node*)malloc(sizeof(treenode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
void postorderTraversal(treenode* A) {
//inorder(A);

    int *res=(int*)malloc(sizeof(int)*3000000);
    int i=0;
    treenode *curr=A,*temp=NULL;
    stack *head=NULL;
    while(curr||!isEmpty(head))
    {
        while(curr)
        {
            push(&head,curr);
            curr=curr->left;
        }
        temp=peek(head);
        if(temp->right==NULL)
        {
            printf("%d ",temp->data);
            pop(&head);
            while(!isEmpty(head)&&peek(head)->right==temp)
            {
                temp=peek(head);
                pop(&head);
                printf("%d ",temp->data);
            }
            curr=peek(head)->right;

        }
        else
        curr=temp->right;
    }

}
int main()
{
    treenode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    postorderTraversal(root);
    return 0;
}

