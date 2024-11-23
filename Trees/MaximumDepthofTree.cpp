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

int findMaxDepth(Node* node){

    if(node == NULL){
        return 0;
    }

    return 1 + max(findMaxDepth(node->left),findMaxDepth(node->right));

}


int main(){

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(8);
    root->right->left = new Node(34);

    root->left->right = new Node(8);

    int ans = findMaxDepth(root);
    cout<<ans;
    return 0;
}