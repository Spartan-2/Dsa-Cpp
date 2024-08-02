#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

void topoSort(vector<pair<int,int>> adjList[],stack<int> &stk,vector<bool> &visited,int node){
    visited[node] = 1;

    for(auto next: adjList[node]){
        if(!visited[next.first]){
            topoSort(adjList,stk,visited,next.first);
        }
    }
    stk.push(node);
    return;
}


vector<int> shortestPath(vector<pair<int,int>> adjList[],int src,int n){
    stack<int> stk;
    vector<bool> visited(n);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            topoSort(adjList,stk,visited,i);
        }
    }
    vector<int> dist(n);
    for(int i =0;i<n;i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    while(!stk.empty()){
        int top = stk.top();
        stk.pop();

        for(auto i: adjList[top]){
            if(dist[top] + i.second == dist[i.first]){
                dist[i.first] = dist[top] + i.second;
            }
        }
    }
    return dist;

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
    vector<int> ans = shortestPath(adjList,src,n);

    for(int i =0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}