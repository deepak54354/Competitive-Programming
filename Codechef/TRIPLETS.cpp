#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9+7)
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
ll p,q,r;
void solve(){
	ll ans = 0;
	cin >> p >> q >> r;
	vll vx(p),vy(q),vz(r);
	vll cum_vx(p),cum_vy(q),cum_vz(r);
	FOR(i,0,p) cin >> vx[i];
	FOR(i,0,q) cin >> vy[i];
	FOR(i,0,r) cin >> vz[i];
	sort(all(vx));sort(all(vy));sort(all(vz));
	cum_vx[0] = vx[0];cum_vy[0] = vy[0];cum_vz[0] = vz[0];
	FOR(i,1,p) cum_vx[i] = (cum_vx[i-1]+vx[i])%MAX;
	FOR(i,1,r) cum_vz[i] = (cum_vz[i-1]+vz[i])%MAX;
	FOR(i,0,q){
		ll y = vy[i];
		ll j = distance(vx.begin(),upper_bound(all(vx),y));
		ll k = distance(vz.begin(),upper_bound(all(vz),y));
		//cout << "Y: " << y << " j: " << j << " k: " << k << endl;
		if(j == 0 || k == 0) continue;
		ll sumx = cum_vx[j-1];
		ll sumz = cum_vz[k-1];
		ans = (ans + (((sumx + (y*j)%MAX)%MAX)*((sumz + (y*k)%MAX)%MAX))%MAX)%MAX;
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