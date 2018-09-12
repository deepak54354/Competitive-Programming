#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 100010;

vector<int> adj[N];
vector<int> vis(N,0);
vector<int> cats(N);

int n,m;

int ans = 0;

void dfs(int u,int sum){
	int curr = 0;
	vis[u] = 1;
	
	if(sum > m)
		return;

	bool isleaf = true;

	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];

		if(!vis[v]){
			if(cats[v] == 0)
				curr = 0;
			else
				curr = sum+1;
			// cout << curr << endl;
			dfs(v,curr);
			isleaf = false;
		}	
	}	
	if(isleaf)
		ans++;
}

void solve(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		cin >> cats[i];

	for(int i = 0; i < n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// res = n;
	dfs(1,cats[1]);
	
	cout << ans << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}