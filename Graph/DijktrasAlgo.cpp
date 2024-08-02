#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> dijktras(int src,int V,vector<vector<pair<int,int>>> adjList){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,src));
    vector<int> dist(V,__INT_MAX__);
    dist[src] = 0;

    while(!pq.empty()){
        pair<int,int> temp = pq.top();
        pq.pop();
        int wt = temp.first;
        int node = temp.second;

        for(auto i :adjList[node]){
            int neighbour = i.first;
            int neighbourWt = i.second;
            if(dist[node]+ neighbourWt < dist[neighbour]){
                dist[neighbour] = dist[node] + neighbourWt;
                pq.push(make_pair(neighbourWt,neighbour));
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
    vector<vector<pair<int,int>>> adjList(n);
    cout<<"enter the number of edges ";
    cin>>e;
    cout<<"Enter the edges ";
    for(int i=0;i<e;i++){
        cin>>u>>v>>wt;
        adjList[u].push_back(make_pair(v,wt));
        adjList[v].push_back(make_pair(v,wt));
    }
    cout<<"Enter the source ";
    cin>>src;
    vector<int> dist = dijktras(src,n,adjList);
    for(auto i:dist){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}