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
	int n,k,ans = 0;
	cin >> n >> k;
	int cn= 0,cp= 0;
	vi p,m;
	FOR(i,0,n-1)
	{
		int x;
		cin >> x;
		if(x > 0)
		{
			p.pb(x);
			ans += x;
		}
		else
			m.pb(x);
	}
	FOR(i,0,m.size()-1.)
	{
		if(k)
		{
			ans += abs(m[i]);
			p.pb(abs(m[i]));
			k--;
		}
		else
			ans += m[i];
	}
	if(k > 0 && k%2)
		ans -= 2*(*min_element(p.begin(),p.end()));
	cout << ans << endl;
	return 0;
}