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
vector<vector<bool> > visit(1001,vector<bool> (1001,0));
vector<vector<pii > > adjx(1001);
vector<vector<pii > > adjy(1001);
void dfs(pii a){
	visit[a.F][a.S]=1;
	for(auto it =adjx[a.F].begin();it!=adjx[a.F].end();it++){
		if(!visit[(*it).F][(*it).S]){
			dfs(*it);
		}
	}
	for(auto it =adjy[a.S].begin();it!=adjy[a.S].end();it++){
		if(!visit[(*it).F][(*it).S]){
			dfs(*it);
		}
	}
}
void solve(){
	int n;
	cin >> n;
	vector<pii > v;
	FOR(i,0,n){
		pii c;
		cin >> c.F >> c.S;
		v.pb(c);
		adjx[c.F].pb(c);
		adjy[c.S].pb(c);
	}
	ll ans = 0;
	FOR(i,0,n){
		if(!visit[v[i].F][v[i].S]){
			dfs(v[i]);
			ans++;
		}
	}
	cout << ans-1 << endl;
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