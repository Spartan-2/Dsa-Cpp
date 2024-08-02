#include<iostream>
#include<vector>
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


int main(){
    DisJointSet ds(6);
    ds.unionByRank(1,1);
    ds.unionByRank(2,5);
    ds.unionByRank(1,5);
    ds.unionByRank(4,6);
    // check if 6 and 3 belong to same disjoint set
    int p1 = ds.findUParent(9);
    int p2 = ds.findUParent(3);
    if(p1 == p2){
        cout<<"Same component "<<endl;
    }else{
        cout<<"Not Same ";
    }
    return 0;
}