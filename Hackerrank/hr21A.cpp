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

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,x;
	cin >> n >> x;
	vector<pair<double,int > >v(n);
	FOR(i,0,n){
		double x1;
		cin >> x1;
		v[i] = make_pair(abs(x1-double(x)),i);
	}
	FOR(i,0,n){
		double v1;
		cin >> v1;
		v[i].F = double(v[i].F)/v1;
	}
	if(n ==1) {
		cout << 0 << endl;
		return 0;
	}
	sort(v.begin(),v.end());
	if(v[1].F-v[0].F <= eps){
		cout << -1 << endl;
	}
	else cout << v[0].S << endl;
	return 0;
}