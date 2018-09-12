#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 200010;
vector<pair<int,long long> > adj[N];

void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	long long ans = (long long)(1e10);
	vector<int> bake(n+1,0);
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		bake[x] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(bake[i] == 1){
			for(int j = 0; j < adj[i].size(); j++){
				if(!bake[adj[i][j].first]){
					ans = min(ans,adj[i][j].second);
				}
			}
		}
	}
	if(ans == 1e10) cout << -1 << endl;
	else cout << ans << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}