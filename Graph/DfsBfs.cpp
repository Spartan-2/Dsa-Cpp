#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

unordered_map <int, list<int>> adjList;
unordered_map <int,bool> visited;
unordered_map <int,bool> visited0;
void createGraph(int u,int v){
    
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    
}

void displayGraph(unordered_map <int, list<int>> &adjList){
    int i,j;
    for(auto i:adjList){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void Bfs(unordered_map <int, list<int>> graph,int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int frontNode = q.front();
        cout<<frontNode<<" ";
        q.pop();
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void Dfs(unordered_map <int, list<int>> graph,int node){
    visited0[node] = true;
    cout<<node<<" ";

    for(auto i: graph[node]){
        if(!visited0[i]){
            Dfs( graph,i);
        }
    }
}

int main(){
    int n,e,u,v;
    int src;
    cout<<"enter the number of vertices :";
    cin>>n;
    cout<<"enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges ";
    for(int i=0;i<e;i++){
        cin>>u>>v;
        createGraph(u,v);
    }
    cout<<"enter source node to traverse graph ";
    cin>> src;
    displayGraph(adjList);
    cout<<"bfs travel ";
    Bfs(adjList,src);
    cout<<"dfs travel";
    Dfs(adjList,src);


    return 0;
}