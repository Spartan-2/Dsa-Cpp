// Given k sorted arrays arranged in the form of a matrix of size k * k.
//  The task is to merge them into one sorted array. Return the merged sorted array 
//  ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).

// GFG Problem

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// love babbar approach complex!!!!!

class node{
    public:
    int data;
    int i;
    int j;

    node(int val,int row,int col){
        data = val;
        i = row;
        j = col;
    }
};

class compare{
    public:
        bool operator()(node* a,node* b){
            return a->data > b->data;
        }
};

vector<int> merge(vector<vector<int>> arr){
    priority_queue<node*,vector<node*>,compare> pq;
    for(int i=0;i<arr.size();i++){
        node* temp = new node(arr[i][0],i,0);
        pq.push(temp);
    }
    vector<int> ans;
    while(!pq.empty()){
        node* top = pq.top();
        ans.push_back(top->data);

        int i = top->i;
        int j = top->j;
        pq.pop();
        if(j+1 < arr[i].size()){
            node* next = new node(arr[i][j+1],i,j+1);
            pq.push(next);
        }
    }

    return ans;

}


// Approach 1
// vector<int> merge(vector<vector<int>> arr){
//         priority_queue<int,vector<int>,greater<int>> pq;
        
//     for(auto it:arr){
//         for(auto it1:it){
//             pq.push(it1);
//         }
//     }
        
//     vector<int> ans;
        
//     while(!pq.empty()){
//         int temp = pq.top();
//         ans.push_back(temp);
//         pq.pop();
//     }
        
//     return ans;
// }




int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> ans = merge(arr);

    for(auto it: ans){
        cout<<it<<endl;
    }
    return 0;
}