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
vll v;
vi fs(5050,0),ls(5050,0);
void solve(){
	cin >> n;
	v.resize(n+1);
	vll dp(n+1,0);
	FOR(i,1,n+1) cin >> v[i];
	FOR(i,1,n+1) if(fs[v[i]]==0) fs[v[i]] = i;
	FORD(i,1,n) if(ls[v[i]]==0) ls[v[i]] = i;
	/*cout << "First positions: " << endl;
	FOR(i,1,n+1) cout << fs[v[i]] << endl;
	cout << "--------------------------------------"<< endl;
	cout << "Last Positions: " << endl;
	FOR(i,1,n+1) cout << ls[v[i]] << endl;
	cout << "---------------------------------------" << endl;*/ 
	FOR(i,1,n+1){
		int x = 0;
		int min_fs = i;
		bool yes = true;
		for(int j = i; j >=min_fs; j--){
			if(ls[v[j]] <= i){
				if(j == ls[v[j]])
					x^=v[j];
				min_fs = min(min_fs,fs[v[j]]);
			}
			else{
				yes = false;
				dp[i] = dp[i-1];
				break;
			}
		}
		if(yes) dp[i] = max(dp[i-1],dp[min_fs-1]+x);
		//cout << "dp: " << dp[i] << " x " << x << endl;
	}
	cout << dp[n] << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}