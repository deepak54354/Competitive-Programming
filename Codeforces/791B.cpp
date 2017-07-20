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
int parent[150005]; vi rnk(150005,1);
int find(int x){
	if(parent[x] != x) 
		parent[x] = find(parent[x]);
	return parent[x];
}
void unite(int x,int y){
	int xp = find(x);
	int yp = find(y);
	if(rnk[xp] < rnk[yp]) parent[xp] = yp;
	else if(rnk[xp] >rnk[yp]) parent[yp] = xp;
	else{
		parent[xp] = yp;
		rnk[yp]++;
	}  
}
void solve(){
	int n,m;
	cin >> n >> m;
	FOR(i,0,n+3) parent[i] = i;
	vi v(n+1,0);
	while(m--){
		int x,y;
		cin >> x >> y;
		v[x]++;v[y]++;
		unite(x,y);
	}
	vi s(n+1,0);
	FOR(i,1,n+1){
		s[find(i)]++;
	}
	FOR(i,1,n+1){
		if(v[i] != s[find(i)]-1){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;

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