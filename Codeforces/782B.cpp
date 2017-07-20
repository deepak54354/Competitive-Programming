#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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
double ans;
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n;
	vi x(n), v(n);
	FOR(i,0,n-1)
		cin >> x[i];
	FOR(i,0,n-1) cin >> v[i];
	double first = 0, last = 1e10;
	while(first+eps < last)
	{
		double t = (first+last)/2;
		double L = 0,R = 1e10;
		FOR(i,0,n-1)
		{
			L = max(L, x[i] - t*v[i]);
			R = min(R, x[i] + t*v[i]);
			//cout << "in loop" << endl;
		}
		if(L < R)
		{
			//cout << "Decreasing" << endl;
			last = t;
		}

		else first = t;
		//cout << "Infinite" << endl;
	}
	cout << fixed << setprecision(13) << last << endl;
	return 0;
}