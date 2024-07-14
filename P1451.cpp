//#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
using namespace std;
const int d[4][2]={0,1,0,-1,1,0,-1,0};
int cell[105][105];
void flood(int x,int y){
    queue<int> q;
    q.push(x);
    q.push(y);
    while(!q.empty()){
        int cx=q.front();
        q.pop();
        int cy=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            if(cell[cx+d[i][0]][cy+d[i][1]]){
                q.push(cx+d[i][0]);
                q.push(cy+d[i][1]);
                cell[cx+d[i][0]][cy+d[i][1]]=0;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a;
            cin>>a;
            cell[i][j]=a-'0';
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cell[i][j]){
                flood(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
