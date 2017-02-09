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
	int n,s,t;
	cin >> n >> s >> t;
	s--;t--;
	int p[n];
	FOR(i,0,n-1)
		cin >> p[i];
	int ans = 0;
	while(s != t && ans <= n)
	{
		s = p[s]-1;
		ans++;
	}
	if(ans > n)
	{
		cout << -1 << endl;
		return 0;
	}	
	cout << ans << endl;
	return 0;
}