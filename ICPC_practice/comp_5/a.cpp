#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5010;

vector<int> adj[N];
vector<int> dist(N,1);
vector<int> vis(N,0);
vector<int> lev_node(N,0);
vector<int> in(N,0);
long long ansc = 0;

void dfs(int u){
	vis[u] = 1;
	// cout << "u: " << u << ",dist[u]: "<< dist[u] << endl;
	for(auto i : adj[u]){
		dist[i] = max(dist[u]+1,dist[i]);
		// cout << dist[i] << endl;
		if(!vis[i])
			dfs(i);
	}
}

long long get_certain(long long a,bool flag){
	int i = 0;
	long long sum = 0;
	while(i < N and (lev_node[i] <= a)){
		sum = 1ll*lev_node[i];
		i++;
	}
	if(flag){
		ansc = (lev_node[i]-lev_node[i-1] - (a-sum)) + (lev_node[N-1]-lev_node[i]);
	}
	return sum;
}

void solve(){
	int a,b,c,e;
	cin >> a >> b >> c >> e;
	while(e--){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		in[y] = 1;
	}

	for(int i = 0; i < c; i++){
		if(in[i]==0){
			dist[i] = 1;
			// cout << i << endl;
			dfs(i);	
		}
	}

	for(int i = 0; i < c; i++){
		// cout << dist[i] << endl;
		lev_node[dist[i]]++;
	}

	for(int i = 1; i < N; i++){
		lev_node[i] += lev_node[i-1];
	}

	// for(int i = 0; i < c; i++){
	// 	// cout << lev_node[i] << endl;
	// }

	long long ansa = get_certain(1ll*a,0);
	long long ansb = get_certain(1ll*b,1);
	cout << ansa << endl;
	cout << ansb << endl;
	cout << ansc << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}