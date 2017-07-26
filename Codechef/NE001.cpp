#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e18)
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
//ifstream in_file("file.in");
void solve(){
	ll n;
	cin >> n;
	vll v(n), cum(n+1,0);
	FOR(i,0,n) cin >> v[i];
	sort(rall(v));
	//cum[0] = v[0];
	FOR(i,1,n+1) cum[i] = cum[i-1]+v[i-1];
	ll i = 0;
	ll tempsum = 0;
	ll ans = cum[n];
	while(i<n){
		tempsum = cum[i+1]*(i+1ll) + cum[n]-cum[i+1];
		//cout << "cum[i+1]: " << cum[i+1] << " cum[n]: " << cum[n] << endl;
		ans = max(tempsum,ans);
		i++;
	}
	cout << ans << endl;
}
int main()
{
	fast_io;
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}