#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Data Types
#define ll long long
#define ul unsigned long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SS stringstream

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int N = 60;
vector<string> adj(N);
int vis[N][N];
int dis[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;

void dfs(pair<int,int> top){
	vis[top.first][top.second]=1;
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		pair<int,int> curr={top.first + dis[i][0],top.second+dis[i][1]};
		if(curr.first >= n or curr.first < 0 or curr.second >= m or curr.second < 0 or vis[curr.first][curr.second]==1 or adj[curr.first][curr.second]=='W'){
			continue;
		}
		dfs(curr);
	}
	return;
}
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> adj[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		for (int j= 0; j < m; ++j)
		{
			/* code */
			if(adj[i][j]=='L' and vis[i][j]!=1){
				dfs({i,j});
				ans++;
			}
		}
	}
	cout << ans << "\n";
	
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}