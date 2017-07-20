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
void solve(){
	int n;
	cin >> n;
	vi v(n);
	FOR(i,0,n) cin >> v[i];
	sort(all(v));
	int a = v[0],b = v[1],c = v[2];
	ll ans = 0;
	if(b==a){
		if(c==a){
			ll num = upper_bound(all(v),a)-lower_bound(all(v),a);
			ans = num*(num-1)*(num-2)/6;
		}
		else{
			ans = upper_bound(all(v),c)-lower_bound(all(v),c);
		}
	}
	else if(c==b){
		ll num = upper_bound(all(v),b)-lower_bound(all(v),b);
		ans = num*(num-1)/2;
	}
	else{
		ans = upper_bound(all(v),c)-lower_bound(all(v),c);
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