// Fibonacci series using recusrsion and memiozation

#include<iostream>
#include<vector>
using namespace std;

// With tabulation 
int f2(int n,vector<int> dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2;i<= n;i++){
        dp[i] = dp[i -1] + dp[i -2];
    }
    return dp[n];
}

// With recurssion and memiozation
int f1(int n,vector<int> &dp){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if( dp[n-1] != -1){
        return dp[n];
    }

    return dp[n] = f1(n-1,dp) + f1(n-2,dp);

}

// With recurssion
int f(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }

    return f(n-1) + f(n-2);
}

int main(){
    int n;
    cout<<"Enter the position for which u want fibonacci number ";
    cin>> n;
    vector<int> dp(n+1,-1);
    vector<int> dp1(n+1);
    //cout<<"With only recurrsion "<<endl;
    //cout<<f(n)<<endl;
    cout<<"With Memoiazation( Top down Approach) "<<endl;
    cout<<f1(n,dp)<<endl;
    cout<<"With Tabulation (Bottom up approach) "<<endl;
    cout<<f2(n,dp1)<<endl;

}