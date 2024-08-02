#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
  public:
          unordered_map <int,list <int>> adjList;
          void addEdge(int u,int v,bool direction){
            adjList[u].push_back(v);
            if(direction){
              adjList[v].push_back(u);
            }
          } 

          void printGraph(){
            for(auto i:adjList){
              cout<<i.first<<"->";
              for(auto j:i.second){
                cout<<j;            
              }
              cout<<endl;
            }
          }

};

int main(){
  graph G;
  int n,u,v;
  cout<<"Enter the number of nodes";
  cin>>n;
  int edges;
  cout<<"Enter the number of edges";
  cin>> edges;
  cout<<"Enter the edge";
  for(int i=1;i<=n;i++){
    cin>>u>>v;
    G.addEdge(u,v,1);
  }

  //printing graph
  G.printGraph();
  return 0;
}
