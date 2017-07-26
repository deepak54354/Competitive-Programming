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
vll L,R;
void solve(){
	cin >> n;
	v.resize(n);
	L.resize(n);R.resize(n);
	ll sum = 0;
	FOR(i,0,n){
		cin >> v[i];
		sum += v[i];
	}
	int k = 0;
	FOR(i,0,n){
		if(v[i] >= k+1)
			k++;
		else k = v[i];
		L[i] = 1ll*k;
	}
	k =0;
	FORD(i,0,n-1){
		if(v[i] >= k+1) k++;
		else k = v[i];
		R[i] = 1ll*k;
	}
	ll ans = MIN;
	FOR(i,0,n){
		ans = max(ans,min(L[i],R[i]));
	}
	cout << sum-ans*ans << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}