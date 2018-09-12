#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int N = 10010;

int vis[N];
vector<int> adj[N];
int color[N];


int n;
int ans = 0;

void dfs(int u){
	vis[u] = true;
	for(auto i : adj[u]){
		if(!vis[i]){
			if(color[u] != color[i]){
				ans++;
				// cout << u << ' ' << i << '\n';
			}

			dfs(i);
		}
	}
}

void solve(){
	cin >> n;

	for(int i = 2; i <= n; i++){
		int x;
		cin >> x;

		adj[x].push_back(i);
		adj[i].push_back(x);
	}

	for(int i = 1; i <=n; i++){
		cin >> color[i];
	}

	dfs(1);

	cout << ans+1 << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}