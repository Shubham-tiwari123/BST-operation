#include <iostream>
#include<queue>
#include "BSTOperations.h"
using namespace std;

void BSTOperations::createBST(){
    cout<<"Enter number of nodes:-";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"\nEnter the data:-";
        cin>>info;
        
        newnode = new node;
        newnode->data = info;
        newnode->left = NULL;
        newnode->right = NULL;
        
        if(root == NULL)
            root = newnode;
        else{
            temp=root;
            while(temp!=NULL){
                if (temp->data < info){
                    prev = temp;
                    temp = temp->right;
                }
                else{
                    prev=temp;
                    temp = temp->left;
                }
            }
            if (prev->data < newnode->data) 
                prev -> right = newnode;
            else 
                prev -> left = newnode;
        }
    }
    cout<<"\nDisplay BST:";
    printInorder(root);
}

void BSTOperations::findMin() {
    temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    cout<<"\nThe minimum element:-"<<temp->data;
}

void BSTOperations::printKeyInRange() {

    cout<<"\nEnter two keys:-";
    cin>>k1>>k2;
    queue <node *> q1,q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                q2.push(q1.front()->left);

            if(q1.front()->right != NULL)
                 q2.push(q1.front()->right);
            
            info = q1.front()->data;
            
            if(k1 <= q1.front()->data && k2 >= q1.front()->data){
                cout<<q1.front()->data<<" ";
            }
            q1.pop();
        }
        while (!q2.empty())
        {
            if (q2.front()->left != NULL)
                q1.push(q2.front()->left);

            if (q2.front()->right != NULL)
                q1.push(q2.front()->right);
            
            info = q1.front()->data;
            
            if(k1 <= q2.front()->data && k2 >= q2.front()->data){
                cout << q2.front()->data <<" ";
            }
            q2.pop();
        }
    }
}

void BSTOperations::printInorder(struct node* newnode)
{
    if (newnode == NULL)
        return;
    printInorder(newnode->left);
    cout<<newnode->data<<" ";
    printInorder(newnode->right);
}

int BSTOperations::makeTree() {
    struct node *roots = newNode(6);
    roots->left        = newNode(10);
    roots->right       = newNode(2);
    roots->left->left  = newNode(1);
    roots->left->right = newNode(3);
    roots->right->right = newNode(12);
    roots->right->left = newNode(7);
    cout<<endl;
    cout<<"Display a general Tree:";
    printInorder(roots);
    swapNode(roots);
}

void BSTOperations::swapNode(struct node* roots){
    cout<<"\nSwapping nodes to make a proper BST:-";
    flag1=0,flag2=0;
    queue <node *> q1,q2;
    q1.push(roots);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                flag1=1;

            if(q1.front()->right != NULL)
                flag2 =1;
            if(flag1==1 && flag2==1){
                if(q1.front()->left->data > q1.front()->data && q1.front()->right->data < q1.front()->data){
                    temp1 = q1.front()->left->data;
                    q1.front()->left->data = q1.front()->right->data;
                    q1.front()->right->data = temp1;
                }
            }
            if(flag1==1){
                q2.push(q1.front()->left);
                flag1=0;
            }
            if(flag2==1){
                q2.push(q1.front()->right);
                flag2=0;
            }
            q1.pop();
        }
        while (!q2.empty())
        {
            if(q2.front()->left != NULL)
                flag1=1;

            if(q2.front()->right != NULL)
                flag2 =1;
            if(flag1==1 && flag2==1){
                if(q2.front()->left->data > q2.front()->data && q2.front()->right->data < q2.front()->data){
                    temp1 = q2.front()->left->data;
                    q2.front()->left->data = q2.front()->right->data;
                    q2.front()->right->data = temp1;
                }
            }
            if(flag1==1){
                q1.push(q2.front()->left);
                flag1=0;
            }
            if(flag2==1){
                q1.push(q2.front()->right);
                flag2=0;
            }
            q2.pop();
        }
    }
    cout<<"\nDisplay BST:";
    printInorder(roots);
}

