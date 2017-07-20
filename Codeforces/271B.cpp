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
int N = 110000;
vi sei;
vector<bool> visit(N,1);
vi nprime(N);
void seive(){
	visit[0] = visit[1] = 0;
	for(int i = 2; i <= sqrt(N);i++){
		if(visit[i])
		{
			//cout << i << endl;
			for(int j = i*i; j < N; j+= i){
				visit[j] = false;
			}
		}
	}
	FOR(i,0,N){
		if(visit[i])
		{
			sei.pb(i);
			//cout << i << endl;
		}
	}
	int i = 0,j = 0;
	while(i<=100000){
		for(int k = i; k <= sei[j]; k++) nprime[k] = sei[j];
		i = sei[j]+1;
		j++;
	}
}
void solve(){
	int n,m;
	cin >> n >> m;
	seive();
	vi row(n),column(m);
	int mat[n][m];
	FOR(i,0,n) FOR(j,0,m) cin >> mat[i][j];
	//FOR(i,0,10) cout << nprime[i] << endl;
	FOR(i,0,n){
		int change = 0;
		FOR(j,0,m) change += nprime[mat[i][j]]-mat[i][j];
		row[i] = change;
		//cout << change << endl;
	}
	//cout << endl;
	FOR(i,0,m){
		int change = 0;
		FOR(j,0,n) change+= nprime[mat[j][i]]-mat[j][i];
		column[i] = change;
		//cout << change << endl;
	}
	int ans = min(*min_element(all(row)),*min_element(all(column)));
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