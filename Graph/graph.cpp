#include<iostream>
#include<vector>
using namespace std;

int main(){
   
    int n,e;
    int u,v;
    cout<<"Enter the number of nodes";
    cin>>n;
    vector<int> adjList[n];
    cout<<"Enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges";

    for(int i = 0;i<e;i++){
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout<<"The adjancey List is"<<endl;
    int j=0;
    for(;j<n;j++){
        cout<<j<<"-> ";
        for(auto i : adjList[j]){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}