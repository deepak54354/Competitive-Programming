#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1000;
vector<int> adj[N];
vector<bool> vis(N,0);
vector<int> dep(N,0);

void dfs(int u){
	vis[u] = 1;
	for(auto i : adj[u]){
		if(!vis[i]){
			dep[i] = dep[u]+1;
			dfs(i);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	map<string,int> s;
	int l = 0;
	for(int i = 0; i < n; i++){
		int x,y;
		string name1,j,name2;
		cin >> name1 >> j >> name2;
		for(int j = 0; j<name1.size();j++) name1[j] = tolower(name1[j]);
		for(int j = 0; j < name2.size(); j++) name2[j] = tolower(name2[j]);
		if(s.find(name1) != s.end()){
			x = s[name1];
		}
		else{
			x = l;
			s.insert({name1,l});
			l++;
		}

		if(s.find(name2) != s.end()){
			y = s[name2];
		}
		else{
			y = l;
			s.insert({name2,l});
			l++;
		}
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1);
	cout << *max_element(all(dep))+1 << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}