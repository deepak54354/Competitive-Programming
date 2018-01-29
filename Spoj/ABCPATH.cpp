#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 51;
char g[N][N];
int vis[N][N];
int dist[N][N];

int n,m;
int c = 0;
int maxi = 0;

int dx[] = {-1,-1,-1,1,1,1,0,0};
int dy[] = {-1,0,1,-1,0,1,-1,1};
queue<pair<int,int> > q;


void bfs(){
	while(!q.empty()){
		pair<int,int> u = q.front(); q.pop();
		for(int i = 0; i < 8; i++){
			pair<int,int> v = {u.first+dy[i],u.second+dx[i]};

			if(v.first >= n or v.first < 0 or v.second >= m or v.second < 0 or vis[v.first][v.second])
				continue;
			else if(int(g[v.first][v.second]) == (int(g[u.first][u.second])+1))
			{
				// cout << u.first << " " << u.second << endl; 
				// cout << v.first << " " <<  v.second << endl;
				// cout << endl << endl;
				dist[v.first][v.second] = max(dist[v.first][v.second],dist[u.first][u.second]+1);
				maxi = max(maxi,dist[v.first][v.second]);
				vis[v.first][v.second] = 1;
				q.push(v);
			}
		}
	}
}
int solve(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			vis[i][j] = 0;
			dist[i][j] = 0;
		}
	}

	cin >> n >> m;
	if(n==0 and m==0) return 0;
	
	c++; maxi = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> g[i][j];
			if(g[i][j] == 'A'){
				dist[i][j] = 1;
				maxi = max(maxi,1);
				q.push({i,j});
			}
		}
	}

	bfs();

	cout << "Case "<< c << ": " << maxi << endl;
	return 1;
}

int main(){
	fast_io;
	// int t;
	// cin>>t;
	while(1){
		int v = solve();
		if(v == 0)
			break;
	}
}