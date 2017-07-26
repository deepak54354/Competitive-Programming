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
#define rall(v) (v).begin(),(v).end()
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
ll n,k,m;
vi parent(100010,0),rnk(100010,1);
vii dp(1005,vi(1005,-1));
int find(int x){
	if(parent[x] != x) parent[x] = find(parent[x]);
	return parent[x];
}

void uniun(int x, int y){
	int px = find(x);
	int py = find(y);

	if(rnk[px]<rnk[py]){
		parent[py] = px;
	}
	else if(rnk[px] > rnk[py]) parent[px] = py;
	else{
		parent[px] = py;
		rnk[py]++;
	}
	return;
}

void solve(){
	cin >> n >> k >> m;
	vi v(m);
	FOR(i,0,n) parent[i] = i;
	FOR(i,0,k){
		int x,y;
		cin >>x>>y;
		x--;y--;
		if(find(x)!=find(y))
			uniun(x,y);
	}
	FOR(i,0,m){
		cin >> v[i];
		v[i]--;
	}
	FOR(i,0,1005) dp[i][i] = 1;
	int i, j, cl;
	 for (cl=2; cl<=m; cl++)
    {
        for (i=0; i<m-cl+1; i++)
        {
            j = i+cl-1;
            if (find(v[i]) == find(v[j]) && cl == 2)
               dp[i][j] = 2;
            else if (find(v[i]) == find(v[j]))
               dp[i][j] = dp[i+1][j-1] + 2;
            else
               dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }
	int ans = dp[0][m-1];
	cout << ans << endl;
}
int main()
{
	//fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}