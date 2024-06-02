//p1314
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005;
struct stone{
	int weight;
	int value;
}st[maxn];
int n,m;
long long int pre_n[maxn],pre_v[maxn],l[maxn],r[maxn];
int mx=INT_MIN,mn=INT_MAX;
long long int Y,s,sum;
bool check(int W){
	Y=0,sum=0;
	memset(pre_n,0,sizeof(pre_n));
	memset(pre_v,0,sizeof(pre_v));
	for(int i=1;i<=n;i++){
		if(st[i].weight>W){
			pre_n[i]=pre_n[i-1]+1;
			pre_v[i]=pre_v[i-1]+st[i].value;
		}
		else {
			pre_n[i]=pre_n[i-1];
			pre_v[i]=pre_v[i-1];
		}
	}
	for(int i=1;i<=m;i++){
		Y+=(pre_v[r[i]]-pre_v[l[i]-1])*(pre_n[r[i]]-pre_n[l[i]-1]);
	}
	sum=llabs(Y-s);
	if(Y>s) return true;
	else return false;
}
int main(){
	cin>>n>>m>>s;
	pre_v[0]=0;
	for(int i=1;i<=n;i++){
		cin>>st[i].weight>>st[i].value;
		mx=max(mx,st[i].weight);
		mn=min(mn,st[i].weight);
	}
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i];
	}
	int left=mn-1,right=mx+2,mid;
	long long ans=0x3f3f3f3f3f3f3f3f;
	while(left<=right){
		mid=left+right>>1;
		if(check(mid)) left=mid+1;
		else right=mid-1;
		if(sum<ans) ans=sum;
	}
	cout<<ans;
	return 0;
}
