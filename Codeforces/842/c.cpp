#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 200010;
vector<int> vis(N,0);
vector<int> a(N);
vector<int> ans(N,0);
vector<vector<int> > adj(N);
vector<int> divi;
vector<int> count_divi;
int n;

void dfs1(int v){
	vis[v] = true;
	for(auto u : adj[v]){
		if(!vis[u])
		{
			ans[u] = max(ans[u],__gcd(ans[v],a[u]));
			dfs1(u);
		}
	}
}

void dfs2(int v, int depth){
	vis[v] = true;
	for(int i = 0; i < divi.size(); i++){
		count_divi[i] += (a[v]%divi[i] == 0);
		if(count_divi[i] >= depth){
			ans[v] = max(ans[v],divi[i]);
		}
	}

	for(auto u :adj[v]){
		if(!vis[u]) dfs2(u,depth+1);
	}

	for(int i = 0; i < divi.size(); i++){
		count_divi[i] -= (a[v]%divi[i]==0);
	}
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x-1].push_back(y-1);
		adj[y-1].push_back(x-1);
	}

	for(int i = 1; i*i <= a[0]; i++){
		if(a[0]%i==0){
			divi.push_back(i);
			if(i != a[0]/i) divi.push_back(a[0]/i);
		}
	}

	sort(all(divi));

	count_divi.resize(divi.size());

	int p = a[0];
	a[0] = 0;
	ans[0] = 0;
	dfs1(0);

	a[0] = p;
	ans[0] = p;
	for(int i = 0; i < n; i++){
		vis[i] = 0;
	}

	dfs2(0,0);

	for(int i = 0; i< n; i++){
		cout << ans[i] << " ";
	}
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