#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX (long long)(1e18)
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
ll n;
ll cost(ll height, vll h, vll c){
	ll ans = 0;
	FOR(i,0,n){
		ans += abs(height-h[i])*c[i];
	}
	return ans;
}
void solve(){
	cin >>n;
	vll h(n),c(n);
	FOR(i,0,n) cin >> h[i];
	FOR(i,0,n) cin >> c[i];
	ll L = 0, R = 100010;
	ll np = 1000;
	while(R-L>=3){
		ll m1 = L+(R-L)/3;
		ll m2 = R-(R-L)/3;
		ll c1 = cost(m1,h,c);
		ll c2 = cost(m2,h,c);
		if(c2>c1) R = m2;
		else L = m1;
	}
	ll ans = MAX;
	FOR(i,L,R+1){
		ans = min(ans,cost(1ll*i,h,c));
	}
	cout << ans << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}