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
#define MAXn (int)(2e6+10)
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
vi arr[MAXn];
vi days[MAXn];
bool foo(int a, int b){
	return arr[a][0] < arr[b][0];
}
bool bar(int a, int b){
	return arr[a][2]<arr[b][2];
}
ifstream in_file("file.in");
void solve(){
	int n,x;
	cin >> n >> x;
	for(int i=0;i<n;i++){
		int l,r,w;
		cin >> l>>r>>w;
		arr[i]={l,r,w};
		days[r-l+1].pb(i);
	}
	multiset<int,bool(*)(int,int)> left(foo), c(bar);
	ll ans = (1e18);
	for(int i = 1; i <x; i++){
		left.clear();c.clear();
		for(auto j : days[i]){
			left.insert(j);
		}
		for(auto j :days[x-i]){
				c.insert(j);
		}
		for(auto e : left){
			while(!c.empty() && arr[*(c.begin())][0] <= arr[e][1]){
				c.erase(c.begin());
			}
			if(!c.empty()){
				ans = min(ans,1ll*(arr[e][2]+arr[*(c.begin())][2]));
			}
		}
	}
	if(ans==1e18){
		cout << -1 <<endl;
	}
	else cout << ans << endl;
}
int main()
{
	fast_io;
	//ofstream out_file("file.out");
	int t=1;
	//in_file >> t;
	while(t--){
		solve();
	}
	return 0;
}