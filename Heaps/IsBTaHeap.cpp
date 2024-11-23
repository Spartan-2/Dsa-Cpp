// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child

// GFG problem 

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

};

int countNodes(TreeNode* node){
    if(node == nullptr){
        return 0;
    }

    int left = countNodes(node->left);
    int right = countNodes(node->right);

    return 1 + left + right;
}

bool isCBT(TreeNode* node,int index,int count){
    int leftChild = index*2 + 1;
    int rightChild = index*2 + 2;
    if(node == nullptr){
        return true;
    }
    if(index > count){
        return false;
    }
    else{
        bool left = isCBT(node->left,leftChild,count);
        bool right = isCBT(node->right,rightChild,count);

        return left && right; 
    }
}

bool isMaxHeap(TreeNode* node){
    if(node->left == nullptr && node->right == nullptr){
        return true;
    }
    if(node->right == nullptr){
        return node->data > node->left->data;
    }
    else{
        int left = isMaxHeap(node->left);
        int right = isMaxHeap(node->right);

        return left && right && (node->data > node->left->data) && (node->data > node->right->data);
    }

}


bool isHeap(TreeNode* root){
    int index = 0;
    int count = countNodes(root);

    if(isCBT(root,index,count) && isMaxHeap(root)){
        return true;
    }

    return false;
}

void cleanup(TreeNode* node){
    if(node){
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }
}


int main(){

}