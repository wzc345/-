//b3631
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000005;
int List[maxn];
void solve(int n){
	int x,y;
	if(n==1){
		cin>>x>>y;
		if(List[x]==x){
			List[x]=y;
		}else{
			int temp=List[x];
			List[x]=y;
			List[y]=temp;
		}
	}else if(n==2){
		cin>>x;
		if(List[x]==x) cout<<"0"<<endl;
		else cout<<List[x]<<endl;
	}else if(n==3){
		cin>>x;
		if(List[List[x]]==List[x]){
			List[x]=x;
		}else{
			int temp=List[x];
			List[x]=List[List[x]];
			List[temp]=temp;
		}
	}
}
int main(){
	int n;
	cin>>n;
	while(n--){
		int t;
		cin>>t;
		solve(t);
	}
}
