//p4017
#include <bits/stdc++.h>
using namespace std;
const int mod=80112002;
const int maxn=5005;
struct animal{
	int pos;
	int num;
	vector<int> next;
}a[maxn];
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> degree(n+1,0);
	bool dis[n+1];
	memset(dis,false,sizeof(dis));
	for(int i=1;i<=m;i++){
	 	int num,next;
	 	cin>>num>>next;
	 	a[num].pos=num;
	 	a[next].pos=next;
	 	a[num].next.push_back(next);
	 	dis[next]=true;
	 	degree[next]++;
	}
	int ans=0;
	queue<animal> que;
	for(int i=1;i<=n;i++){
		if(!dis[i]){
			a[i].num=1;
			que.push(a[i]);
		}
	}
	while(!que.empty()){
		animal mid=que.front();
		que.pop();
		int len=mid.next.size();
        for (int nextPos : mid.next) {
            a[nextPos].num = (a[nextPos].num + mid.num) % mod;
            degree[nextPos]--;
            if (degree[nextPos] == 0) {
                que.push(a[nextPos]);
            }
        }
	}
	for(int i=1;i<=n;i++){
		if(a[i].next.empty()) ans=(ans+a[i].num)%mod;
	}
	cout<<ans;
}

