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
int n,q;
void solve(){
	cin >> n >> q;
	vi s(n,0);
	while(q--){
		int type;
		cin >> type;
		if(type==1){
			int j,a;
			cin >> j >> a;
			if(j==0)s[j]=a;
			else s[j]=a|s[j-1];
			FOR(i,j+1,n) s[i]=s[i]|s[i-1];
		}
		else{
			int k;
			cin >> k;
			ll powset = 1<<n;
			bool flag = false;
			for(int i = 0; i <= powset; i++){
				int x = 0;
				for(int j = 0; j < n; j++){
					if(i&(1<<j)){
						x^=s[j];
					}
				}
				if(x==k){
					flag = 1;
					break;
				}
			}
			cout << (flag?"YES":"NO") << endl;
		}
	}
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}