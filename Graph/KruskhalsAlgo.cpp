#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisJointSet{
    vector<int> parent,oize,rank;
    public:
    DisJointSet(int V){
        oize.resize(V+1,1);
        rank.resize(V+1,0);
        parent.resize(V+1);
        for(int i =0;i<=V;i++){
            parent[i] = i;
        }
    }
    int findUParent(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u] = findUParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);

        if(ult_u == ult_v){
            return;
        }
        else if(ult_u != ult_v){
            if(rank[ult_u] < rank[ult_v]){
                parent[u] = v;
            }
            else if(rank[ult_u] == rank[ult_v]){
                parent[ult_v] = ult_u;
                rank[ult_u] ++;
            }
            else{
                parent[ult_v] = ult_u;
            }
        }
    }
};

int kruskhals(vector<vector<pair<int,int>>>& adjList,int V,vector<int>& mst){

    vector<pair<int,pair<int,int>>> edges(V);
    DisJointSet ds(V);
    int minWt;
    for(int i =0;i<V;i++){
        for(auto j: adjList[i]){
            int v = j.first;
            int wt = j.second;
            int u = i;
            edges.push_back({wt,{u,v}});
        }

        sort(edges.begin(),edges.end());

        for(int i =0;i<V;i++){
            pair<int,pair<int,int>> temp = edges[i];
            int weight = temp.first;
            int u = temp.second.first;
            int v = temp.second.second;

            if(ds.findUParent(u) != ds.findUParent(v)){
                minWt += weight;
                mst[u] = v;
                ds.unionByRank(u,v);

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
        adjList[v].push_back(make_pair(v,wt));
    }
     vector<int> mst(n);
    int ans = kruskhals(adjList,n,mst);
    cout<<endl<<ans<<endl;
    return 0;
}