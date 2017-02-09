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
	vi v;
	FOR(i,0,n-1)
		cin >> a[i];
	int l = 0,r = 2;
	while(r < n)
	{
		if(a[r] == a[r-1]+a[r-2])
			r++;
		else
		{
			v.pb(r-l);
			l = r-1;
			r = r+1;
		}
	}
	v.pb(n-l);
	cout << *max_element(v.begin(),v.end()) << endl;
  	return 0;
}
