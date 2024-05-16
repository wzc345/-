//p2786
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
map<string,ll> m;
int main(){
	int N,P;
	cin>>N>>P;
	while(N--){
		string word;
		ll value;
		cin>>word>>value;
		m[word]=value;
	}
	string t="";
	char c;
	while(scanf("%c",&c)!=EOF){
		if(!(isdigit(c)||isalpha(c))){
			ans=((ans%P)+m[t]%P)%P;
			t="";
		}
		else t+=c;
	}
	cout<<ans;
	return 0;
}
