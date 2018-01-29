#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100010;

vector<pair<int,long long> > adj[N];
vector<int> vis(N,0);
vector<long long> dist(N,0);

int n;

long long dfs(int u){
	vis[u] = 1;

	cout << u << "-> " << endl;
	for(int i = 0; i < adj[u].size(); i++){
		
		int v = adj[u][i].first;
		long long w = adj[u][i].second;

		if(!vis[v]){
			dist[u] = max(dist[u],dfs(v)+w);
		}
		else 
			dist[u] = max(dist[u],dist[v]+w);
		cout << u << ": " << dist[u] << " " << v << ": " << dist[v] << endl;
	}
	return dist[u];
}

void solve(){
	for(int i = 0; i < N; i++){
		adj[i].clear();
		vis[i] = 0;
		dist[0] = 0;
	}

	cin >> n;
	for(int i = 0; i< n-1; i++){
		int x,y;
		long long w;
		cin >> x >> y >> w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}

	dist[1] = dfs(1);

	for(int i = 1; i <= n; i++){
		cout << dist[i] << " ";
	}

	cout << endl;
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}