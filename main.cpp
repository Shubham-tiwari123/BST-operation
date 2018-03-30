#include <iostream>
#include "BSTOperations.h"
using namespace std;

int main() {
    BSTOperations b,b1,b3;
    /*Create a BST*/
    b.createBST();
    /*Display a BST using inorder traversel*/
    b.printInorder(b.getroot());
    /*Finding the minimum value*/
    b.findMin();
    /*Print the values between the two range*/
    b.printKeyInRange();
    /*Make a simple tree and then convert it into BST*/
    b.makeTree();
    b.printInorder(b.getroots());
    cout<<endl;
    cout<<"Display a general Tree:";
    /*Converting general tree to BST*/
    b.swapNode(b.getroots());
    b.printInorder(b.getroots());
    b1.createBST();
    b1.printInorder(b.getroot());
    /*Merging two BST*/
    cout<<"\nAfter merging tree:";
    b3.mergeTwoBST(b,b1);
    b3.printInorder(b.getroot());
    /*Finding the largest subtree of BST*/
    b.largestBSTSubtree(b.getroot()->left,0);
    b.largestBSTSubtree(b.getroot()->right,1);
    /*Inorder Successor in Binary Search Tree*/
    b.inorderSuccessor(b.getroot(),b.getroot()->left->right->right);
    /*Sorted order printing of a given array that represents a BST*/
    b.sortedOrderOfArrayBST();
    return 0;
}