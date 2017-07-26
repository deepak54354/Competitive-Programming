#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
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
int m,k;
void solve(){
	cin >> m >> k;
	vi p(m);
	FOR(i,0,m) cin >> p[i];
	ll L = *max_element(all(p));
	ll R = accumulate(all(p),0);
	int workers = 0;
	while(L<R){
		ll x = L + (R-L)/2;
		//cout << "R: " << R << " L: " << L << " X: " << x << endl;
		workers = 1;
		ll sum = 0;
		FOR(i,0,m){
			if(sum+p[i]<=x) sum+=p[i];
			else{
				workers++;
				sum = p[i];
			}
		}
		if(workers<=k)
			R = x;
		else L = x+1;
	}
	ll sum = 0;
	vi t;
	int partitions = k-1;
	FORD(i,0,m-1){
		if(sum+p[i]<=R && partitions <= i){
			t.pb(p[i]);
			sum+=p[i];
			continue;
		}
		else{
			t.pb(-1);
			t.pb(p[i]);
			partitions--;
			sum=p[i];
		}
	}
	FORD(i,0,t.size()-1){
		if(t[i]==-1) cout << "/ ";
		else cout << t[i] << " ";
	}
	cout << endl;
	return;
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