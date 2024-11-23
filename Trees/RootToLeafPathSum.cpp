#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// FAILED ATTEMPT


// void postOrder(Node* node,string &str,vector<int> &ans){
//     if(node == nullptr){
//         ans.push_back(stoi(str));
        
//         return;
//     }
//     str.push_back(node->data);
//     postOrder(node->left,str,ans);
//     postOrder(node->right,str,ans);
//     str.pop_back();

// }

// int TreePathsSum(Node* root){
//     if(root == nullptr){
//         cout<<"here";
//         return 0;
//     }
//     string str ="";
//     vector<int> ans;
//     int sum = 0;
//     postOrder(root,str,ans);
//     for(auto it:ans){
//         sum += it;
//     }
//     for(auto it:ans){
//         cout<<it<<" ";
//     }
//     return sum/2;
// }

// PASSED ATTEMPT

void dfs(Node* node,int n,int& sum){
    if(node == nullptr) return;
    if(node->left == nullptr && node->right == nullptr){
        sum += node->data + 10*n;
        return;
    }
    dfs(node->left,10*n + node->data,sum);
    dfs(node->right,10*n + node->data,sum);
}

int treePathsSum(Node* root){
    if(root == nullptr) return 0;
    int sum = 0;
    dfs(root,0,sum);

    return sum;
}

int main(){
    struct Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(5);

    root->right->right = new Node(4);
    root->left->left = new Node(2);

    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    int ans = treePathsSum(root);
    cout<<endl<<ans<<endl;
}