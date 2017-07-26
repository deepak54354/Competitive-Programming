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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).end()
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
int n,k;
void solve(){
	cin >> n >> k;
	vector<vector<int> > v(n);
	vector<vector<bool> > s(n, vector<bool>(k+1,0));
	//v.resize(n);
	//s.resize(n, vector<bool> (k+1,0));
	FOR(i,0,n){
		int c;
		cin >> c;
		FOR(j,0,c){
			int f;
			cin >> f;
			v[i].pb(f);
			s[i][f]=1;
		}
	}
	vector<vector<int> > missing(n);
	FOR(i,0,n){
		FOR(j,1,k+1){
			if(s[i][j] ==0) missing[i].pb(j);
		}
	}
	ll ans = 0;
	FOR(i,0,n){
		FOR(j,i+1,n){
			bool flag = true;
			if(v[i].size()+v[j].size() < k) continue;
			else{
				FOR(m,0,missing[i].size()){
					if(s[j][missing[i][m]]==0){
						flag = false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
	}
	cout << ans << endl;
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