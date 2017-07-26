#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
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
char recurse(ll length, bool flag,ll k){
	ll a1=(length-1)/2;
	ll a2=(length+1)/2;
	if(k==1) return 'a';
	else if(k==length) return 'c';
	else if(k==a2){
		if(flag) return 'c';
		else return 'a';
	}
	else if(k>a1) return recurse(a1,1,k-a2);
	else return recurse(a1,0,k);
}
void solve(){
	ll k;
	cin >> k;
	ll length = 1;
	while(length<k){
		length=2*length+1;
	}
	length=2*length+1;
	cout << recurse(length,0,k) << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}