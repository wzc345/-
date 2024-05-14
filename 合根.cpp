//p8654
#include<bits/stdc++.h>
using namespace std;
class dis_set{
	private:
		int m,n;
		vector<int> num;
		vector<int> depth;
	public:
		void get(){
			cin>>m>>n;
			num.resize(m*n+1);
			depth.assign(m*n+1,0);
			for(int i=1;i<=m*n;i++){
				num[i]=i;
			}
		}
		int find(int x){
			if(num[x]!=x){
				num[x]=find(num[x]);
			}
			return num[x];
		}
		void Union(int n1,int n2){
			int root1=find(n1);
			int root2=find(n2);
			if(root1!=root2){
				num[root1]=root2;
			}
		}
		void get_depth(){
			for(int i=1;i<=m*n;i++){
				depth[find(i)]++;
			} 
		}
		void ans(){
			int ans=0;
			for(int i:depth){
				if(i>0) ans++;
			}
			cout<<ans;
		}
};
int main(){
	dis_set s;
	s.get();
	int k;
	cin>>k;
	while(k--){
		int a,b;
		cin>>a>>b;
		s.Union(a,b);
	}
	s.get_depth();
	s.ans();
}
