#ifndef BSTOPERATIONS_H
#define BSTOPERATIONS_H

class BSTOperations{
private:
    struct node{
        int data;
        node *left;
        node *right;
    };
    node *root,*temp,*newnode,*prev;
    int num,info,k1,k2;
    int temp1,flag1,flag2;
public:
    void createBST();
    void printInorder(struct node* newnode);
    void findMin();
    void printKeyInRange();
    int makeTree();
    void swapNode(struct node* roots);
    
    struct node *newNode(int data){
        struct node *newnodes = new node;
        newnodes->data = data;
        newnodes->left = NULL;
        newnodes->right = NULL;
        return(newnodes);
    }
    
    BSTOperations(){
        root = NULL;
    }
};


#endif /* BSTOPERATIONS_H */

