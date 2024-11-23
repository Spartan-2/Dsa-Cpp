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

// naive approach

// int leftSubtreeHeight(Node* node){
    

// }
// int rightSubtreeHeight(Node* node){
    

// }


// bool checkBalancedBT(Node* node){

//     static bool ifBalance;

//     if(node == NULL){
//         return true;
//     }

//     int lh = leftSubtreeHeight(node->left);
//     int rh = rightSubtreeHeight(node->right);

//     if(abs(lh - rh) > 1){
        
//         return false;
//     }
    // if(ifBalance == false){
    //     return false;
    // }

//     bool checkLeft = checkBalancedBT(node->left);
//     bool checkRight = checkBalancedBT(node->right);

//     if(!checkLeft || !checkRight){
//         return false;
//     }

//     return true;

// }

// optimized approach by modifying the function which inds the max depth of the tree

int checkBalanceBT2(Node* node){
    if(node == NULL){
        return 0;
    }
    int lh = checkBalanceBT2(node->left);
    int rh = checkBalanceBT2(node->right);

    if(lh == -1 || rh == -1){
        return -1;
    }

    if(abs(lh - rh) > 1){
        return -1;
    }

    return 1 + max(lh,rh);
}

int main(){

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(8);
    root->right->left = new Node(34);

    root->left->right = new Node(8);

    int check;
    check = checkBalanceBT2(root);
    if(check != -1){
        cout<<"The Binary Tree is balanced "<<endl;
    }else{
        cout<<"The Binary Tree is not balanced "<<endl;
    }

    return 0;
}