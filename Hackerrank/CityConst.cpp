#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

ll mod(ll a, ll b) // calculates a%b, not remainder
{
	ll ans;
	if(b == 0)
		return -1;
	else
	{
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	}
	return ans;
}
int n,m;
vii dp;
bool update(vii adj, int u, int v){
	if(dp[u][v]) return 1;
	FOR(i,0,adj[v].size()){
		if(update(adj, u, adj[v][i]) == 1){
			dp[u][v] = 1;
			return 1;
		}
	}
	return 0;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> m;
	dp.resize(n+1,vi(n+1,0));
	FOR(i,1,n+1) dp[i][i] = 1;
	vii adj(n+1, vi);
	FOR(i,0,m){
		int x,y;
		cin >> x >> y;
		adj[y].pb(x);
	}
	update(adj)
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int x,d;
			cin >> x >> d;
			if(d == 0) adj.pb(vi(1,x));
			else adj[x].pb(n+1);
			n++;
			dp.pb(vi(n+1,0));
		}
		else{
			int x,y;
			bool ans = update()
		}
	}
	return 0;
}