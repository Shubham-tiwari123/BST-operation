#include <iostream>
#include<queue>
#include <vector>
#include<iterator>
#include<algorithm>
#include "BSTOperations.h"
using namespace std;

void BSTOperations::createBST(){
    cout<<"\nEnter number of nodes:-";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"\nEnter the data:-";
        cin>>info;
        addNode(info);
    }
    cout<<"\nDisplay BST:";
}

void BSTOperations::addNode(int data) {
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

int BSTOperations::makeTree(){
    roots = newNode(6);
    roots->left        = newNode(10);
    roots->right       = newNode(2);
    roots->left->left  = newNode(1);
    roots->left->right = newNode(3);
    roots->right->right = newNode(12);
    roots->right->left = newNode(7);
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
}

void BSTOperations::mergeTwoBST(BSTOperations b1,BSTOperations b2) {
    int i,j,k,m,n,x;
    vector<int>v,v1;
    vector<int>::iterator it;
    queue <node *> q1,q2;
    q1.push(b1.root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                q2.push(q1.front()->left);

            if(q1.front()->right != NULL)
                 q2.push(q1.front()->right);
            
            v.push_back(q1.front()->data);
            q1.pop();
        }
        while (!q2.empty())
        {
            if (q2.front()->left != NULL)
                q1.push(q2.front()->left);

            if (q2.front()->right != NULL)
                q1.push(q2.front()->right);
            
            v.push_back(q2.front()->data);
            q2.pop();
        }
    }
    
    q1.push(b2.root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL)
                q2.push(q1.front()->left);

            if(q1.front()->right != NULL)
                 q2.push(q1.front()->right);
            
            v1.push_back(q1.front()->data);
            q1.pop();
        }
        while (!q2.empty())
        {
            if (q2.front()->left != NULL)
                q1.push(q2.front()->left);

            if (q2.front()->right != NULL)
                q1.push(q2.front()->right);
            
            v1.push_back(q2.front()->data);
            q2.pop();
        }
    }
    sort(v.begin(),v.end());
    sort (v1.begin(),v1.end());
    
    m = v.size();
    n = v1.size();
    int v3[m+n];
    i=0,j=0,k=0;
    cout<<"\nmerging two list:";
    while (i < m && j < n){
        if (v[i] < v1[j])
        {
            v3[k] = v[i];
            i++;
        }
        else
        {
            v3[k] = v1[j];
            j++;
        }
        k++;
    }
    while (i < m){
         v3[k] = v[i];
         i++; k++;
    }
    while (j < n){
        v3[k] = v1[j];
        j++;k++;
    }
    root = NULL;
    for(int a=0;a<(m+n);a++){
        info = v3[a];
        addNode(info);
    }
}

void BSTOperations::largestBSTSubtree(struct node *temp1,int x) {
    int count[2]={1,1};
    int n,m;
    queue <node *> q1,q2;
    temp = temp1;
    q1.push(temp);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            if(q1.front()->left != NULL){
               q2.push(q1.front()->left);
               count[x]++;
            }
            if(q1.front()->right != NULL){
                q2.push(q1.front()->right);
                count[x]++;
            }
            q1.pop();
        }
        while (!q2.empty())
        {
            if (q2.front()->left != NULL){
                q1.push(q2.front()->left);
                count[x]++;
            }
            if (q2.front()->right != NULL){
                q1.push(q2.front()->right);
                count[x]++;
            }
            q2.pop();
        }
    }
    if(x==0){
        n = count[0];
    }
    else if(x==1){
        m = count[1];
        if(n>m)
            cout<<"\nLeft subtree has more elements:-"<<n;
        else
            cout<<"\nRight subtree has more elements:-"<<m;
    }
}

void BSTOperations::inorderSuccessor(node* temp1, node* temp2) {
    if(temp2->right!=NULL){
        node *current = temp2->right;
        while (current->left != NULL) {
            current = current->left;
        }
        cout<<"\nSuccessor:-"<<current->data;
    }
    else{
        node *succ = NULL;
 
        while (temp1 != NULL){
            if (temp2->data < temp1->data)
            {
                succ = temp1;
                temp1 = temp1->left;
            }
            else if (temp2->data > temp1->data)
                temp1 = temp1->right;
            else
               break;
        }
        cout<<"\nSuccessor:-"<<succ->data;
    }
}

void BSTOperations::sortedOrderOfArrayBST() {
    cout<<"\nGiven an array the represents BST:-";
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    cout<<"\nSorting the array:-";
    sortArray(arr,0,4);
}

void BSTOperations::sortArray(int arr[], int x, int y) {
    if(x > y)
        return;
    sortArray(arr, x*2 + 1, y);
    cout<<arr[x];
    sortArray(arr, x*2 + 2, y);  
}