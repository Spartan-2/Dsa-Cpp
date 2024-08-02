#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int primsAlgo(vector<vector<pair<int,int>>> adjList,vector<int> (&mst)){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,-1});
    vector<int> parent(adjList.size());
    vector<bool> visited(0,adjList.size());
    int minWt = 0;
    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        int node = temp.second;
        int wt = temp.first;
        if(visited[node] == 1){
            continue;
        }
        visited[node] = 1;
        minWt += wt;
        mst[node] = parent[node];

        for(auto i : adjList[node]){
            int neighbour = i.first;
            int weight = i.second;
            if(!visited[neighbour]){
                pq.push({weight,neighbour});
                parent[neighbour] = node;
            }
        }         
    }
    return minWt;
}


int main(){
    int n,e,u,v;
    int wt;
    int src;
    cout<<"enter the number of vertices :";
    cin>>n;
    vector<vector<pair<int,int>>> adjList(n);
    cout<<"enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges ";
    for(int i=0;i<e;i++){
        cin>>u>>v>>wt;
        adjList[u].push_back(make_pair(v,wt));
        adjList[v].push_back(make_pair(u,wt));
    }
    vector<int> mst(n);
    int ans = primsAlgo(adjList,mst);
    cout<<"Minimun cost of spaning tree "<<ans<<endl;
    cout<<"Edges of the min spanning tree ";
    for(int i =0;i<mst.size();i++){
        cout<<i<<"---"<<mst[i]<<endl;
    }

    return 0;
}