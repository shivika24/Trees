#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
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
treenode* newNode(int data)
{
    treenode* node = (treenode*)malloc(sizeof(treenode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
void levelorderTraversal(treenode* root)
{
 queue<treenode*>q;
 q.push(root);
 q.push(NULL);
 while(!q.empty())
 {
     if(q.front()!=NULL)
        cout<<q.front()->data<<" ";
     if(q.front()->left!=NULL)
        q.push(q.front()->left);
     if(q.front()->right!=NULL)
        q.push(q.front()->right);
     q.pop();
     if(q.front()==NULL)
     {
     cout<<"$";
     q.pop();
     q.push(NULL);
     }
     if(q.front()==NULL&&q.size()==1)
        break;
 }
}
int main()
{
    treenode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelorderTraversal(root);
}
