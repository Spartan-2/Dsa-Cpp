// Khans Algorithm (Topological sort using BFS)

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<int> kahnAlgo(vector<int> adjList[],int numNodes){
    vector<int> inDegree(numNodes,0);
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<numNodes;i++){
        for(auto j: adjList[i]){
            inDegree[j]++;
        }
    }
    for(int i=0 ;i<numNodes;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto neighbour : adjList[node]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}


int main(){
    int n,e;
    int v,u;
    cout<<"Enter the number of nodes ";
    cin>>n;
    vector<int> adjList[n];
    cout<<"Enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges";

    for(int i = 0;i<e;i++){
        cin>>u>>v;
        adjList[u].push_back(v);
    }
    vector<int> ans = kahnAlgo(adjList,n);
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}