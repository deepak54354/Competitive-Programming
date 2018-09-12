#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100010;

vector< vector<int>> adj(N);
vector<bool> vis(N,0);
vector<int> color(N,-1);

void dfs(int u, int c){
	vis[u] = 1;
	for(auto i : adj[u]){
		if(!vis[i]){
			color[i] = (1-c);
			dfs(i,1-c); 
		}
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vis[1]=1;
	color[1] = 0;
	dfs(1,0);
	long long c[2];
	c[0]=c[1] = 0ll;
	for(int i = 1; i <= n; i++){
		// cout << color[i] << " ";
		c[color[i]]++;
	}
	cout << c[0]*c[1] - (n-1) << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}