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
	int n,k;
	cin >> n >> k;
	int a[n];
	FOR(i,0,n-1)
		cin >> a[i];
	vi v;
	int initialize = 0;
	FOR(i,0,k-1)
		initialize += a[i];
	v.pb(initialize);
	int temp = 0;
	FOR(i,k,n-1)
	{
		initialize = initialize-a[temp]+a[i];
		v.pb(initialize);
		temp++;
	}
	cout << (min_element(v.begin(),v.end())-v.begin() + 1) << endl;
	return 0;
}