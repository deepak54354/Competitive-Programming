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
#define F firsat
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
void solve(){
	int n;
	cin >> n;
	vi v(n+1);
	vll w(n+1);
	w[0] = 0;
	FOR(i,1,n+1) cin >> v[i];
	FOR(i,1,n+1){
		cin >> w[i];
		w[i] += w[i-1];
	}
	//partial_sum(w.begin(),w.end(),w);
	int l,r;
	l = r = 1;
	vector<int> check(n+1,0);
	ll sum = -1;
	bool flag = true;
	while(l<=n){
		if(l > 1) check[v[l-1]]--;
		while(r<=n){
			if(!check[v[r]]){
				check[v[r]]++;
				r++;
			}
			else{
				flag = false;
				break;
			}
		}
		sum = max(sum,w[r-1]-w[l-1]);
		l++;
	}
	cout << sum << endl;
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