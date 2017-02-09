#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX 1e9
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
ll sum_dig(ll temp)
{
	ll sum = 0;
	while(temp)
	{
		sum += temp%10;
		temp /=10;
	}
	return sum;
}
ll poww(ll p,ll q)
{
	ll res =1;
	FOR(i,1,q)
	{
		res *= p;
	}
	return res;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int p,q,r;
	cin >> p >> q >> r;
	int ans = 0;
	vector<ll> v;
	FOR(i,1,81)
	{
		ll x = q*(poww(i,p)) + r;
		if(x>MAX)
			break;
		if(sum_dig(x) == i)
		{
			ans++;
			v.pb(x);
		}
		//cout << ans << " ";
	}
	cout << ans << endl;
	if(ans == 0)
		return 0;
	FOR(i,0,v.size()-1)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}