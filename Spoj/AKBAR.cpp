#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1000010;

vector<int> adj[N];
vector<int> weight(N,-1);
vector<int> vis(N,0);
vector<int> id(N,-1);

bool flag = true;

void bfs(queue<int> q){
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(auto v : adj[u]){
			if(!vis[v]){
				vis[v] = 1;
				if(weight[u] > 0){
					weight[v] = weight[u]-1;
					id[v] = id[u];
				}
				q.push(v);
			}
			else{
				if(weight[v] > 0 and weight[u] > 0 and id[v] != id[u]){
					flag = false;
					return;
				}
				if(weight[v] == -1 and weight[u] > 0){
					weight[v] = weight[u]-1;
					id[v] = id[u];
				}
			}
		}
	}
}

void solve(){
	flag = true;
	queue<int> q;
	int n,r,m;
	cin >> n >> r >> m;

	for(int i = 1; i <= n; i++){
		adj[i].clear();
		vis[i] = 0;
		weight[i] = -1;
		id[i] = -1;
	}

	while(r--){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	while(m--){
		int k,s;
		cin >> k >> s;
		weight[k] = s;
		vis[k] = 1;
		id[k] = k;
		q.push(k);
	}

	bfs(q);

	for(int i = 1; i <= n; i++){
		if(weight[i] == -1){
			flag = false;
			break;
		}
	}
	cout << (flag?"Yes":"No") << '\n';
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}