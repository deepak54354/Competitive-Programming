#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) ((n)*(n))
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
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
#define M 1000000007
int main()
{
	fast_io;
	//ifstream in_file(file.in);
	//ofstream out_file(file.out);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		ll ans = 0;
		if(n < 3)
			ans = 0;
		else
		{
			for(int i = 2; i <= n; i+= 2)
			{
				ans = (ans + ((n-i)*(n-i)))%M;
			}
			ll fac = 1;
			for(int i = 1; i < n-2;i++)
			{
				fac = ((fac)*(i))%M;
			}
			ans = (ans*((n-2)))%M;
			ans = (2*ans*fac)%M;
		}
		cout << ans << endl;
	}
	return 0;
}