#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> shortestPath(vector<int> adjList[],int n,int s,int e){
    vector<int> visited(n);
    queue<int> q;
    vector<int> parent(n);
    q.push(s);
    parent[s] = -1;
    int front;
    visited[s] = 1;
    while(!q.empty()){
        front = q.front();
        q.pop();
        
        for(auto i: adjList[front]){
            if(visited[i] != 1){
                q.push(i);
                visited[i] = 1;
                parent[i] = front;
            }
        }
    }
    vector<int> ans;
    int currentNode = e;
    ans.push_back(currentNode);
    
    while(1){
        currentNode = parent[currentNode];
        if(currentNode == -1){
            break;
        }
        else{
            ans.push_back(currentNode);
        }
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    int n,e;
    int u,v;
    cout<<"Enter the number of nodes ";
    cin>> n;
    vector<int> adjList[n];
    cout<<"Enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges "<<endl;   
    for(int i = 0;i<e;i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int end,start;
    cout<<"Enter the start node ";
    cin>>start;
    cout<<"Enter the end node ";
    cin>>end;
    vector<int> ans = shortestPath(adjList,n,start,end);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}