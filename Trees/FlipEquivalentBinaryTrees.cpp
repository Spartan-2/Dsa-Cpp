#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};


// bool flipEquiv(TreeNode* root1,TreeNode* root2){
//     queue<TreeNode*> q1;
//     queue<TreeNode*> q2;

//     if(root1->data != root2->data){
//         return false;
//     }

//     q1.push(root1);
//     q2.push(root2);

//     while((!q1.empty()) && (!q2.empty())){
//         TreeNode* front1 = q1.front();
//         TreeNode* front2 = q2.front();

//         if(front1->data != front2-> data || q1.size() != q2.size()){
//             return false;
//         }
//         q1.pop();
//         q2.pop();

//         if(front1->left != NULL && front1->right != NULL){
//             q1.push(front1->left);
//             q1.push(front1->right);
//         }
//         if(front2->left != NULL && front2->right != NULL){
//             q1.push(front2->left);
//             q1.push(front2->right);
//         }

//     }
//     return true;

// }
bool recur(TreeNode* node1,TreeNode* node2){
    if(node1 != nullptr && node2 != nullptr){
        return true;
    }
    if(node1->data != node2->data){
        return false;
    }
}

bool flipEquvi(TreeNode* root1,TreeNode* root2){
    bool a = recur(root1->left,root2->left) && recur(root1->right,root2->right);
    bool b = recur(root1->right,root2->left) && recur(root1->left,root2->right);

    return a || b;
}

int main(){

}