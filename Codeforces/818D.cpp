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
void solve(){
	int n,a;
	cin >> n >> a;
	set<int> s;
	vi v(n);
	vi count(1000005);
	FOR(i,0,n){
		cin >> v[i];
		count[v[i]]++;
	}
	int countmax= count[a];
	FOR(i,1,1000001){
		if(count[i]>=countmax && i!=a) s.insert(i);
	}
	FORD(i,0,n-1){
		if(v[i]!=a){
			if(s.find(v[i])!=s.end()){
				count[v[i]]--;
				if(count[v[i]] < count[a]) s.erase(v[i]);
			}
		}
		else{
			count[a]--;
		}
	}
	if(s.size()>=1) cout << *s.begin() << endl;
	else cout << -1 << endl;
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