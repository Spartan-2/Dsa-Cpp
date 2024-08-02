
// Failed Attempt

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct job{
    int finish,start,wt;
};

bool sortComporator(pair<pair<int,int>,int> i1,pair<pair<int,int>,int> i2){
    return (i1.first.first < i2.first.first);
}
int p(int j,vector<pair<pair<int,int>,int>> interval){
    for(int i = j-2;i>=0;i--){
        if (interval[i].first.first <= interval[j-1].first.second){
            return i;
        }
    }
    return 0;
}

int OPT(int j,vector<int>& M,vector<pair<pair<int,int>,int>> interval){
    if(j == 0){
        return 0;
    }
    if(M[j]){
        return M[j] ;
    }
    else{
        M[j] = max(interval[j-1].second + OPT(p(j,interval),M,interval),OPT(j-1,M,interval));
    }
}

vector<int> WIS(vector<pair<pair<int,int>,int>> interval,int N){
    sort(interval.begin(),interval.end(),sortComporator);
    vector<int> M(N+1);
    M[0] = 0;

    int m = OPT(N,M,interval);
    return M;
}
int main(){
    int n,finish,start,wt;
    cout<<"Enter the number of jobs ";
    vector<pair<pair<int,int>,int>> interval(n);
    cout<<"Enter finish time,start time,weight ";
    for(int i=0;i<n;i++){
        cin>>finish>>start>>wt;
        interval.push_back({{finish,start},wt});
    }
    vector<int> ans = WIS(interval,n);
    for(auto i: ans){
        cout<<i<<" ";
    }


    return 0;
}