#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2010;

vector<int> adj[N];
vector<bool> vis(N,0);
vector<int> depth(N,0);

void dfs(int u){
	vis[u] = true;
	for(auto i : adj[u])
		if(!vis[i])
		{
			depth[i] = 1+depth[u];
			dfs(i);
		}
}

void solve(){
	int n;
	cin >> n;
	vector<int> l;
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		if(a!=-1){
			adj[a].push_back(i);
		}
		else 
			l.push_back(i);
	}
	int ans = 0;
	for(auto i : l){
		depth[i] = 1;
		dfs(i);
	}
	cout << *max_element(all(depth)) << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}