#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 200010;

vector<int> adj[N];
vector<int> x(N);
vector<int> vis(N,0);

int dfs(int v){
	vis[v] = true;
	for(auto i : adj[v]){
		if(!vis[i])
			x[v] = x[v] xor (dfs(i));
	}
	return x[v];
}

void solve(){
	int n,q;
	cin >> n >> q;
	for(int i = 0; i< n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 0; i < n; i++)
		cin >> x[i];

	int xo[501];
	for(int i = 1; i<=500; i++){
		for(int j = 0; j < n; j++){
			vis[j] = 0;
		}
		x[0] = dfs(0);
		xo[i] = x[0];
	}
	while(q--){
		int f;
		cin >> f;
		if(f <=500){
			cout << xo[f] << endl;
		}
		else cout << 0 << endl;
	}
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}