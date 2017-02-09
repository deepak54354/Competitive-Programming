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
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

int main()
{
	fast_io;
	//ifstream in_file(file.in);
	//ofstream out_file(file.out);
	int t;
	cin >> t;
	while(t--)
	{
		int N;
		cin >> N;
		vi a(N),b(N);
		FOR(i,0,N-1)
			cin >> a[i];
		FOR(i,0,N-1)
			cin >> b[i];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ll ans = 0;
		FOR(i,0,N-1)
		{
			ans += a[i]*b[i];
		}
		cout << ans << endl;
	}
	return 0;
}