#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100010;
const int MAX = 1000000000;
int n,q;
vector<int> a(N+1, -1);
vector<vector<pair<int,int> > > v(N+1);


bool bfs(int u){
	queue<int> q;
	q.push(u);
	a[u]=0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(int i = 0; i < v[x].size(); i++)
		{
			int w = v[x][i].second;
			int node = v[x][i].first;

			if(w == 0){
				if(a[node]==-1){
					a[node] = a[x];
					q.push(node);
				}
				else if(a[node]!=a[x]) return false;
			} 

			else{
				if(a[node]==-1){
					a[node] = 1-a[x];
					q.push(node);
				}
				else if(a[node] != 1-a[x]){
					return false;
				}
			}
		}
	}
	return true;
}

void solve(){
	bool ans = true;
	scanf("%d %d", &n,&q);

	for(int i = 0; i <= n; i++)
	{
		a[i] = -1;
		v[i].clear();
	}

	for(int i = 0; i < q; i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if( x==y and w != 0){
			ans = false;
		}
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}

	if(!ans)
	{
		printf("no\n");
		return;
	}

	for(int i = 1; i <=n; i++){
		if(a[i]==-1){
			ans &= bfs(i);
		}
	}
	printf((ans?"yes\n":"no\n"));
}

int main(){
	//fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}