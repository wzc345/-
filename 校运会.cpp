//p2256
#include<bits/stdc++.h>
using namespace std;
map<string,string> m;
string Find(string name){
	if(m[name]!=name){
		m[name]=Find(m[name]);
	}
	return m[name];
}
void Union(string n1,string n2){
	string root1=Find(n1);
	string root2=Find(n2);
	if(root1!=root2){
		m[root1]=root2;
	}
}
int main(){
	int N,M;
	cin>>N>>M;
	while(N--){
		string name;
		cin>>name;
		m[name]=name;
	}
	while(M--){
		string n1,n2;
		cin>>n1>>n2;
		Union(n1,n2);
	}
	int K;
	cin>>K;
	while(K--){
		string f1,f2;
		cin>>f1>>f2;
		if(Find(f1)!=Find(f2)) cout<<"No."<<endl;
		else cout<<"Yes."<<endl;
	}
}
