// You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

// We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.


// Leetcode 632. Smallest Range Covering Elements from K Lists

#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>

using namespace std;


struct node{
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

vector<int> kSorted(vector<vector<int>> arr){

    priority_queue<node*,vector<node*>,compare> pq;

    int min = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxi = max(maxi,arr[i][0]);
        node* first = new node(arr[i][0],i,0);
        pq.push(first);
    }

    
    vector<int>ans;
    ans.push_back(0);
    ans.push_back(INT_MAX);

    while(!pq.empty()){
        node* top = pq.top();
        pq.pop();

        min = top->data;
        int row = top->i;
        int col = top->j;

        if(maxi - min < ans[1] - ans[0]){
            ans[0] = min;
            ans[1] = maxi;
        }

        if(col+1 < arr[row].size()){
            maxi = max(maxi,arr[row][col+1]);
            node* next = new node(arr[row][col+1],row,col+1);
            pq.push(next);
        }else{
            break;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr =  {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> ans = kSorted(arr);

    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}