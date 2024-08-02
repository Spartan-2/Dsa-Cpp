#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node,vector<pair<int,int>> adjList[],stack<int> stk,vector<bool> &visited){
    if(visited[node] == true){
        return;
    }
    visited[node] = true;
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,adjList,stk,visited);
        }
    }
    stk.push(node);
    return;
}

vector<int> shortestPath(vector<pair<int,int>> (&adjList)[],int src){
    vector<bool> visited(adjList->size());
    stack<int> stk;
    for(int i = 0;i<adjList->size();i++){
        dfs(i,adjList,stk,visited);
    }

}


int main(){
    int n,e,u,v;
    int wt;
    int src;
    cout<<"enter the number of vertices :";
    cin>>n;
    vector<pair<int,int>> adjList[n];
    cout<<"enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges ";
    for(int i=0;i<e;i++){
        cin>>u>>v>>wt;
        adjList[u].push_back(make_pair(v,wt));
    }
    cout<<"Enter source node ";
    cin>> src;
    vector<int> ans = shortestPath(adjList,src);

    return 0;
}