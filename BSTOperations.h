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
public:
    void createBST();
    void levelOrder(node *root);
    void findMin();
    void printKeyInRange();
    BSTOperations(){
        root = NULL;
    }
};


#endif /* BSTOPERATIONS_H */

