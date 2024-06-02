//p1719
#include<bits/stdc++.h>
using namespace std;
const int maxn=125;
int pre[maxn][maxn];
int num[maxn][maxn];
int main(){
	int n;
	cin>>n;
	int ans=INT_MIN;
	memset(pre,0,sizeof(pre));
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>num[i][j];
			pre[i][j]=pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+num[i][j];
			ans=max(ans,num[i][j]);
			ans=max(pre[i][j],ans);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int h=i;h<=n;h++){
				for(int k=j;k<=n;k++){
					ans=max(ans,pre[h][k]-pre[h][j-1]-pre[i-1][k]+pre[i-1][j-1]);
				}
			}
		}
	}
	cout<<ans;
}  
