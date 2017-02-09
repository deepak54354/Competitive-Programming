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
	set<int> ans;
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		int c0 = 0;
		int c = 0;
		int c1 = 0;
		FOR(i,0,n-1)
		{
			ll x;
			cin >> x;
			if(x ==1)
			{
				c++;
				c0++;
			}
			else if(x == 0)
				c++;
			else if(x == -1)
				c1++;
		}		
		if((c1 > 1 && c0 > 0 && c == n-c1) || (c1 == 1 && n == 1)) cout << "yes" << endl;
		else if(c == n-1 || c== n)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}	
	return 0;
}