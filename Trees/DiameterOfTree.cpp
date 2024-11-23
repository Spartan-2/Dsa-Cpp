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





// optimized approach 
int findDiameter(Node* node,int &maxi){
    if(node == nullptr){
        return 0;
    }
    int lh = findDiameter(node->left,maxi);
    int rh = findDiameter(node->right,maxi);

    maxi = max(maxi,lh + rh);

    return 1 + max(lh,rh);
}

int main(){
    int maxi = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(8);
    root->right->left = new Node(34);

    root->left->right = new Node(8);

    int depth = findDiameter(root,maxi);

    cout<<"Depth of BT "<<depth<<" Diameter of BT "<<maxi<<endl;
    return 0;
}