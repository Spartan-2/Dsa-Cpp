// 100. Same Tree

// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left = right = NULL;
    }
};

bool isSameTree(Node* p,Node* q){
    if((q == nullptr) || (p == nullptr)){
        return (p == q);
    }
    return (p-> data == q->data) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right));
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(6);
    root1->right = new Node(0);
    Node* root2 = new Node(2);
    root2->left = new Node(6);
    root2->right = new Node(8);

    bool flag = isSameTree(root1,root2);
    if(flag) cout<<"YESS";
    else cout<<"NOOOOOOO";
    return 0;
}