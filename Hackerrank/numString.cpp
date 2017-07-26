#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
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
ll m;
ll fast_exp(int base,int n)
{
  ll ans = 1;
  while(n)
  {
    if(n%2==1)
      ans = (ans*base)%m;

    base = (base*base)%m;
    n = n>>1;
  }
  return ans%m;
}

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	string s;
	cin >> s;
	ll k,b;
	cin >> k >> b >> m;
	ll sum= 0;
	int n = s.size();
	ll val = 0;
	FOR(i,0,k){
		val = (val+((s[i]-'0')*fast_exp(b,k-i-1))%m);
	}
	//cout << val << endl;
	sum = (sum+mod(val,m));
	//cout << sum << endl;
	FOR(i,1,n-k+1){
		val = ((b*val)%m - ((s[i-1]-'0')*fast_exp(b,k)))%m + (s[i+k-1]-'0')%m;
		//cout << sub << endl;
			//cout << val << endl;
		val = mod(val,m);
			sum = (sum+val);
			//cout << sum << endl;
	}
	cout << sum << endl;
	return 0;
}