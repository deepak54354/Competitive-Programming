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
int n,k1,k2;
vi s1,s2;
vii dp;
int func(vi s, int i, int j){
	if(dp[j-1][i] != -1)
		return dp[j-1][i];
	if(i == 0){
		dp[j-1][i] = 1;
		return 1;
	}
	
}
int main()
{// 0-> lose 1-> win 2-> loop
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n;
	dp.resize(2,vi (n,-1)); 
	cin >> k1;
	s1.resize(k1);
	FOR(i,0,k1) cin >> s1[i];
	cin >> k2;
	s2.resize(k2);
	FOR(i,0,k2) cin >> s2[i];
	FOR(i,1,n){
		dp[1][i] = func(s1,i,1);
		dp[2][i] = func(s2,i,2);
	}
	return 0;
}