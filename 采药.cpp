//p1048
#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,M;
	cin>>T>>M;
	vector<int> value(M+1,0),time(M+1,0);
	for(int i=1;i<=M;i++){
		cin>>time[i]>>value[i];
	}
	int dp[M+1][T+1]={0};
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=M;i++){
		for(int j=0;j<=T;j++){
			if(time[i]<=j) dp[i][j]=max(dp[i-1][j-time[i]]+value[i],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
		}
	}
	cout<<dp[M][T];
}
