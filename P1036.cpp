//#include<bits/stdc++.h> 
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
bool is_pri(int n){
    if(n==1) return false;
    int mid=sqrt(n);
    for(int i=2;i<=mid;i++){
        if(n%i==0) return false;
    }
    return true;
}
int ans=0;
void DFS(vector<int> num,int k,int m,int startx,int sum){
    if(m==k){
        if(is_pri(sum)){
            ans++;
        }
        return;
    }
    for(int i=startx;i<num.size();i++){
        DFS(num,k,m+1,i+1,sum+num[i]);
    }
    return;
}
int main( )
{
    int n,k;
    cin>>n>>k;
    vector<int> num(n,0);
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    DFS(num,k,0,0,0);
    cout<<ans;
    return 0;
}
