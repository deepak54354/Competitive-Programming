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
vector <ll> v;

void gen_lucky(ll x)
{
	if(x > (ll)(1e9 + 10))
		return;
	v.pb(x*10+4);
	v.pb(x*10+7);
	gen_lucky(x*10+4);
	gen_lucky(x*10+7);
	return;
}

bool count(ll x)
{
	int count4 = 0,count7 = 0;
	while(x)
	{
		if(x%10 == 4)
			count4++;
		else
			count7++;
		x/=10;
	}
	if(count4 == count7)
		return true;
	return false;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	ll n;
	cin >> n;
	gen_lucky(0);
	sort(v.begin(),v.end());
	int len = v.size();
	ll ans;
	FOR(i,0,len-1)
	{
		if(count(v[i]) && v[i] >= n)
		{
			ans = v[i];
			break;
		}
	}
	cout << ans << endl;
	return 0;
}