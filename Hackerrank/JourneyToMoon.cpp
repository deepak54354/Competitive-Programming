#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
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
vii adj(100003);
vector<bool> visit(100003,0);
int v;
void dfs(int x){
	visit[x]=1;
	for(auto it = adj[x].begin();it!=adj[x].end();it++){
		if(!visit[*it])
		{
			dfs(*it);
			v++;
		}
	}
}
void solve(){
	int n,p;
	cin >> n >> p;
	vi ver;
	while(p--){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ver.pb(0);
	FOR(i,0,n){
		v=1;
		if(!visit[i]){
			dfs(i);
			ver.pb(v);
		}
	}
	ll ans =0;
	int sz = ver.size();
	FOR(i,1,sz) ver[i]+=ver[i-1];
	FOR(i,1,sz){
		ans += 1ll*(ver[i]-ver[i-1])*(ver[sz-1]-ver[i]);
	}
	cout << ans << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}