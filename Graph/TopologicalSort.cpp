#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

void Dfs(int node,unordered_map<int , list<int>> &adjList,unordered_map <int , bool> &visited, stack<int> &stk){
    if(visited[node] == true){
        return;
    }
    visited[node] = true;
    for(auto i:adjList[node]){
        if(!visited[i]){
            Dfs(i,adjList,visited,stk);
        }
    }
    stk.push(node);
    return;
}

vector<int> topologicalSort(int n,unordered_map<int , list<int>> adjList){
    unordered_map <int , bool> visited;
    stack<int> stk;
    vector<int> ans;
    for(int node =0;node<n;node++){
        Dfs(node,adjList,visited,stk);
    }
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;

}
int main(){
    unordered_map<int , list<int>> adjList;
    int n,e,u,v;
    int src;
    cout<<"enter the number of vertices :";
    cin>>n;
    cout<<"enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges ";
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    vector<int> ans = topologicalSort(n,adjList);

    for(auto i :ans){
        cout<<i<<" ";
    }
    return 0;
}