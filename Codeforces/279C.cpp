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
int rt[100001],lt[100001];
void solve(){
	int n,m;
	cin >> n >> m;
	vi v(n);
	FOR(i,0,n) cin >> v[i];
	lt[0] = 0;
	rt[n-1] = n-1;
	FOR(i,1,n){
		if(v[i]<=v[i-1])
			lt[i] = lt[i-1];
		else lt[i] = i;
	}
	FORD(i,0,n-2){
		if(v[i]<=v[i+1])
			rt[i] = rt[i+1];
		else 
			rt[i] = i;
	}
	FOR(i,0,m){
		int l,r;
		cin >> l >> r;
		l--;r--;
		bool flag = (rt[l]>=lt[r]);
		cout << (flag?"Yes":"No") << endl;
	}
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