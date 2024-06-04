//p1002
#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int Map[maxn][maxn];
bool s[maxn][maxn];
const int d[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
void dis(int xm,int ym){
	for(int i=0;i<8;i++){
		s[xm+d[i][0]][ym+d[i][1]]=true;
	}
	s[xm][ym]=true;
}
int main(){
	int n,m,xm,ym;
	cin>>n>>m>>xm>>ym;
	memset(Map,0,sizeof(Map));
	Map[0][0]=1;
	dis(xm,ym);
	for(int i=1;i<=n;i++){
		if(!s[i][0]) Map[i][0]=Map[i-1][0];
	}
	for(int j=1;j<=m;j++){
		if(!s[0][j]) Map[0][j]=Map[0][j-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!s[i][j]) Map[i][j]=Map[i-1][j]+Map[i][j-1];
		}
	}
	cout<<Map[n][m];
}
