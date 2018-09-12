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
vector<int> vis(N,-1);
vector<int> a;
vector<int> b;
bool yes = 0;

void dfs(int u, int c){
	vis[u] = c;
	if(!c) a.push_back(u);
	else b.push_back(u);
	for(auto i : adj[u]){
		if(vis[i] == -1)
			dfs(i,1-c);
		else if(vis[i] != 1-c){
			yes = 1;
			return;
		} 
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i<= n; i++){
		if(vis[i]==-1)
			dfs(i,0);
	}
	if(yes)
	{
		cout << -1 << endl;
		return;
	}
	cout << a.size() << endl;
	for(auto i : a)
		cout << i << " ";
	cout << endl << b.size() << endl;
	for(auto i :  b)
		cout << i << " ";
	cout << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}