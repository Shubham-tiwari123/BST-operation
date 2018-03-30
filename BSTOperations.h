#ifndef BSTOPERATIONS_H
#define BSTOPERATIONS_H

class BSTOperations{
private:
    struct node{
        int data;
        node *left;
        node *right;
    };
    node *root,*temp,*newnode,*prev,*roots;
    int num,info,k1,k2;
    int temp1,flag1,flag2;
    int flag3;
    int arr[5] = {4, 2, 5, 1, 3};
public:
    void createBST();
    void addNode(int data);
    void printInorder(struct node* newnode);
    void findMin();
    void printKeyInRange();
    int makeTree();
    void swapNode(struct node* roots);
    void mergeTwoBST(BSTOperations b1,BSTOperations b2);
    void largestBSTSubtree(struct node *temp1,int x);
    void inorderSuccessor(struct node *temp1,struct node *temp2);
    void sortedOrderOfArrayBST();
    void sortArray(int arr[],int x,int y);
    
    struct node *getroot(){
        return root;
    }
    struct node *getroots(){
        return roots;
    }
    
    
    struct node *newNode(int data){
        struct node *newnodes = new node;
        newnodes->data = data;
        newnodes->left = NULL;
        newnodes->right = NULL;
        return(newnodes);
    }
    
    BSTOperations(){
        root = NULL;
        roots = NULL;
    }
};


#endif /* BSTOPERATIONS_H */