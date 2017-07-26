#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX 1ll<<60
#define MIN 1ll*(-MAX)
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
int n;
ll l,x,y;
vll v;
ll func(ll k){
	ll ans = 0;
	FOR(i,0,n){
		ans += abs(v[i]-k-1ll*(i)*l);
	}
	return ans;
}
ll terSearch(ll start,ll end){
	while(end-start>=3)
	{
		ll m1 = start+(end-start)/3;
		ll m2 = end-(end-start)/3;
		ll f1 = func(m1); ll f2 = func(m2);
		if(f1 < f2)
			end = m2;
		else start = m1;
	}
	//cout << start << endl;
	ll ans = MAX;
	FOR(i,start,end+1){
		ans = min(ans,func(i));
	}
	return ans;
}

void solve(){
	sort(v.begin(),v.end());
	cout << terSearch(x,y-n*l) << endl; 
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--){
		cin >> n >> l >> x >> y;
		v.resize(n);
		FOR(i,0,n) cin >> v[i];
		solve();
	}
	return 0;
}