#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
unordered_map <int, list<int>> adjList;
unordered_map <int,bool> visited;

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

bool findCyclic(unordered_map <int, list<int>> graph,int src){
    unordered_map <int , int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;
    int i;

    int count = 0;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto i : adjList[frontNode]){
            cout<<i<<endl;
            if(visited[i]== true && i != parent[frontNode]){
                int c = parent[i];
                cout<<c<<endl;
                return true;
            }
            if(!visited[i]){
                count ++;
                cout<<count<<endl;
                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
            }
        }
    }
    return false;
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

    bool ans = findCyclic(adjList,src);
    if(ans == true){
        cout<<"cycle is present";
    }else{
        cout<<"cycle is not present";
    }
    return 0;
}