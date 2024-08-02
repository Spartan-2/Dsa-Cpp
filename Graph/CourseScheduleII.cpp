#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prereq){
    vector<int> aas = {};
    vector<int> ans;
    if(prereq.size() == 0){
        for(int i=0;i<numCourses;i++){
            ans.push_back(i);
        }
        return ans;
    }
    vector<int> adjList[numCourses];
    queue<int> q;
    vector<int> inDegree(numCourses,0);
    for(int i = 0;i<prereq.size();i++){
        adjList[prereq[i][1]].push_back(prereq[i][0]);
    }
    for(int i = 0; i< numCourses;i++){
        for(auto j : adjList[i]){
            inDegree[j]++;
        }
    }
    for(int i = 0; i< numCourses;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        count++;
        for(auto neighbour : adjList[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(count == numCourses)
        return ans;
    else
        return aas;
}
int main(){
    vector<vector<int>> prereq = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> ans = findOrder(4,prereq);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}