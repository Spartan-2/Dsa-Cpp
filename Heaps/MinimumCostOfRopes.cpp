// GFG problem topic-heaps


// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost.
// The cost to connect two ropes is the sum of their lengths. 

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

long long minCost(vector<long long> &arr){
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    vector<long long> temp;
    long long ans = 0;
    for(auto it: arr){
        pq.push(it);
    }
    while(pq.size() > 1){
        long long temp1 = pq.top();
        pq.pop();
        long long temp2 = pq.top();
        pq.pop();
            
        long long sum = temp1 + temp2;
        pq.push(sum);
        ans += sum;
    }
    return ans;
}


int main(){

}