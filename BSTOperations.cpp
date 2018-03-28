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
    levelOrder(root);
}

void BSTOperations::levelOrder(node *root){
    queue <node *> q1,q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                q2.push(q1.front()->left);

            if(q1.front()->right != NULL)
                 q2.push(q1.front()->right);
            cout<<q1.front()->data<<" ";
            q1.pop();
        }
        while (!q2.empty())
        {
            if (q2.front()->left != NULL)
                q1.push(q2.front()->left);

            if (q2.front()->right != NULL)
                q1.push(q2.front()->right);

            cout << q2.front()->data <<" ";
            q2.pop();
        }
    }
}

void BSTOperations::findMin() {
    temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    cout<<"\nThe minimum element:-"<<temp->data;
}

void BSTOperations::printKeyInRange() {
    temp = root;
    cout<<"\nEnter two keys:-";
    cin>>k1>>k2;
    queue <node *> q1,q2;
    q1.push(temp);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                q2.push(q1.front()->left);

            if(q1.front()->right != NULL)
                 q2.push(q1.front()->right);
            
            info = q1.front()->data;
            
            if(k1 <= q1.front()->data && k2 >= q1.front()->data){
                cout<<"yo";
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
                cout<<"hi";
                cout << q2.front()->data <<" ";
            }
            q2.pop();
        }
    }
}


