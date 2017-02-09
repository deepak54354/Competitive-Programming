#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
int main()
{
	fast_io;
	int n;
	cin >> n;
	ll a[n];
	FOR(i,0,n-1)
		cin >> a[i];
	int q;
	cin >> q;
	ll w1=0,h1=0,ans=0;
	FOR(i,0,q-1)
	{
		ll w2,h2;
		cin >> w2 >> h2;
		ans = max(ans+h1,a[w2-1]);
		w1 = w2;
		h1= h2;
		cout << ans << endl;
	}	
	return 0;
}