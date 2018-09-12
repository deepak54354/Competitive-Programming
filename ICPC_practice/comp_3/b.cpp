#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2e3;
vector<vector<int>> adj(N);
vector<int> dis(N,0);
vector<string> v(N);
int n,d;

int t;

void dfs(int u){
	vis[u]=1;
	for(auto i : adj[u])
		if(!vis[i]){
			dis[i]=dis[u]+1;
			dfs(i);
		}
}

void solve(){
	for(int i = 0; i < N; i++){
		vis[i]=dis[i]=0;
		adj[i].clear();
	}
	int j = 0;
	cin >> n >> d;
	while(n--){
		string s;
		cin >> s;
		int u;
		if(v.find(s)==v.end()){
			v[j]=s;
			j++;
			u=j-1;
		}
		int c;
		cin >> c;
		while(c--){
			string f;
			cin >> f;
			if(v.find(f)==v.end()){
				v[j]=f;
				j++;
				adj[u].push_back(j-1);
			}
			else{
				int k = v.find(f)-v.begin();
				adj[u].push_back(k);
			}
		}
	}
	dfs(0);
	vector<int> a(N,0);
	for(int i = 0; i < j; i++){
		a[dis[i]]++;
	}
	vector<pair<int,int>> ans(j+1);
	for(int i = 0; i < j; i++){
		child.push_back({})
	}
}

int main(){
	fast_io;
	cin>>t;
	for(int i= 0; i < t; i++){
		solve();
	}
}