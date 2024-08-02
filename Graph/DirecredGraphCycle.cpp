// To check wether a cycle is present or not in a directed Graph



#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

bool Dfs(unordered_map <int , list<int>> &adjList,unordered_map <int, bool> &visited,int node,unordered_map <int, bool> dfsVisited){
   
    visited[node] = true;
    dfsVisited[node] = true;
    for(auto neighbour : adjList[node]){
        if(!visited[neighbour]){
            bool ans = Dfs(adjList,visited,neighbour,dfsVisited);
            if(ans){
                return true;
            }
        }
        else if(dfsVisited[neighbour] == true){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}


bool detectCycleDirectedDFS(unordered_map <int , list<int>> &adjList){

    unordered_map <int, bool> visited;
    unordered_map <int, bool> dfsVisited;
    int num = adjList.size();
    for(int i =1 ;i <=num; i++){
        if(!visited[i]){
           bool cycleFound = Dfs(adjList,visited,i,dfsVisited);
           if(cycleFound){
            return true;
           }
        }
    }
    return false;
}

int main(){
    unordered_map <int , list<int>> adjList;
    int n,u,v;
    cout<<"Enter the number of nodes";
    cin>>n;
    int edges;
    cout<<"Enter the number of edges";
    cin>> edges;
    cout<<"Enter the edge";
    for(int i=1;i<=n;i++){
      cin>>u>>v;
      adjList[u].push_back(v);
    }
    bool ans = detectCycleDirectedDFS(adjList);
    if(ans){
        cout<<"cycle present"<<endl;
    }else{
        cout<<"cycle not present"<<endl;
    }
    return 0;

}