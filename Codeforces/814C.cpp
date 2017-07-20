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
int n,q;
string s;
int dp[27][1501];
int change(int k,char x){
	int l,r;
	l = r = 0;
	int moves = 0,ans = 0;
	while(l<n){
		while(r<n){
			if(s[r] != x){
				if(moves<k)moves++;
				else break;
			}
			r++;
		}
		ans = max(ans,r-l);
		if(s[l] !=x)moves--;
		l++;
	}
	return ans;
}
void solve(){
	cin >> n >> s >> q;
	FOR(i,0,26){
		FOR(j,1,1501){
			dp[i][j] = change(j,'a'+i);
		}
	}
	FOR(i,0,q){
		int k;
		char c;
		cin >> k >> c;
		cout << dp[c-'a'][k] << endl;
	}
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	solve();
	return 0;
}