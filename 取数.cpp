//p1123 
#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
const int d[8][2]={-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};
int Map[maxn][maxn];
int dis[maxn][maxn];
int m,n,mx,ans;
void Plus(int x,int y){
	for(int i=0;i<8;i++){
		++dis[x+d[i][0]][y+d[i][1]];
	}
}
void erease(int x,int y){
	for(int i=0;i<8;i++){
		--dis[x+d[i][0]][y+d[i][1]];
	}
}
void DFS(int x,int y){
	if(y==m+1){
		DFS(x+1,1);
		return;
	}
	if(x==n+1){
		mx=max(ans,mx);
		return;
	}
	if(!dis[x][y]){
		ans+=Map[x][y];
		Plus(x,y);
		DFS(x,y+1);
		erease(x,y);
		ans-=Map[x][y];
	}
	DFS(x,y+1);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		mx=0;
		ans=0;
		memset(Map,0,sizeof(Map));
		memset(dis,0,sizeof(dis));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>Map[i][j];
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<Map[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		DFS(1,1);
		cout<<mx<<endl;
	}
}
