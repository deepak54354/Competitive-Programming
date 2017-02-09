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
	ll n;
	cin >> n;
	vector<ll> v(n);
	FOR(i,0,n-1)
		cin >> v[i];
	sort(v.begin(),v.end());
	ll maxi = v[n-1]-v[0];
	if(v[n-1] == v[0])
	{
		cout << 0 << " "  << n*(n-1)/2<< endl;
		return 0;
	}
	ll c1 = count(v.begin(),v.end(),v[0]);
	ll  c2 = count(v.begin(),v.end(),v[n-1]);
	ll ways = c2*c1;
	cout << maxi << " " << ways <<endl;	
	return 0;
}