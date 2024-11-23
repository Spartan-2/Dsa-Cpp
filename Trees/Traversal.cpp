#include<iostream>
#include<vector>
#include<queue>
#include<stack>

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

void inorderTraversal(struct Node *node){

    if(node ==NULL){
        return;
    }

    inorderTraversal(node->left);
    cout<<(*node).data;
    inorderTraversal(node->right);
}

void preorderTraversal(Node *node){
    if(node == NULL){
        return;
    }

    cout<<node->data;
    preorderTraversal((*node).left);
    preorderTraversal((*node).right);
}

void postorderTraversal(Node* node){

    if(node == NULL){
        return;
    }
    
    postorderTraversal((*node).left);
    postorderTraversal((*node).right);
    cout<<(*node).data;
}

// iterative approach to inorder traversal

void iterativeInorder(Node* root,vector<int> &ans){

    stack<Node*> stk;
    Node* node = root;

    if(node == NULL) return;

    while(true){

        if(node != NULL){
            stk.push(node);
            node = (*node).left;
        }else{
            if(stk.empty()){
                return;
            }
            node = stk.top();
            stk.pop();
            ans.push_back((*node).data);
            node = node->right;

        }
    }   
}

// postorder using two stacks 

void postorderModified(Node* node){

    stack<Node*> stk1;
    stack<Node*> stk2;

    stk1.push(node);
    
    while(!stk1.empty()){
        node = stk1.top();
        stk2.push(node);
        stk1.pop();

        if(node->left != NULL){
            stk1.push(node->left);
        }
        if(node->right != NULL){
            stk1.push(node->right);
        }
    }

    while(!stk2.empty()){
        cout<<stk2.top()->data<<"\t";
        stk2.pop();
    }

}


// iterative post order with one stack

void postorderModified2(Node* node,vector<int> &ans){

    stack<Node*> stk;
    Node *cur = node;
    Node *temp;

    while(cur != NULL || !stk.empty()){

        if(cur != NULL){
            stk.push(cur);
            cur = cur->left;
        }else{
            temp = stk.top()-> right;
            if(temp == NULL){
                temp = stk.top();
                ans.push_back((*temp).data);
                stk.pop();

                while(!stk.empty() && temp == stk.top()->right){
                    temp = stk.top();
                    stk.pop();
                    ans.push_back((*temp).data);
                }

            }else{
                cur = temp;
            }
        }
    }
}


// preorder postorder and inorder using one single stack

void allTraversals(Node* node){
    stack<pair<Node*,int>> stk;
    stk.push({node,1});
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    while(!stk.empty()){
        auto top = stk.top();
        stk.pop();

        if(top.second == 1){
            preorder.push_back(top.first->data);
            stk.push({top.first,top.second++});

            if(top.first->left != NULL){
                stk.push({top.first->left,1});
            }
        }else if(top.second == 2){
            inorder.push_back(top.first->data);
            stk.push({top.first,top.second++});

            if(top.first->right != NULL){
                stk.push({top.first->right,2});
            }
        }else{
            postorder.push_back(top.first->data);
        }
    }
}

// memory management deleting the used memory

void cleanup(Node* node){
    if(node){
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }
}

int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(8);
    root->right->left = new Node(34);

    root->left->right = new Node(8);

    vector<int> ans;

    // inorderTraversal(root);
    // preorderTraversal(root);
    // postorderTraversal(root);
    // iterativeInorder(root,ans);
    postorderModified2(root,ans);

    for(auto it:ans){
        cout<<it<<"\t";
    }

    // postorderModified(root);

    cleanup(root);


    return 0;
}