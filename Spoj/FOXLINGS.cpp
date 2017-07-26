#include <bits/stdc++.h>
#include <bitset>
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
map<int,int> parent;
map<int,int> rnk;
int fnd(int x){
	if(parent[x] != x) parent[x] = fnd(parent[x]);
	return parent[x];
}

void unite(int x,int y){
	int xp = fnd(x);
	int yp = fnd(y);
	if(rnk[xp] < rnk[yp]) parent[xp] = yp;
	else if(rnk[xp] > rnk[yp]) parent[yp] = xp;
	else{
		parent[xp]= yp;
		rnk[yp]++;
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	ll co = n;
	set<int> s1;
	while(m--){
		int x,y;
		cin >> x >> y;
		s1.insert(x);
		s1.insert(y);
		if(!parent[x]){
			parent[x] = x;
			rnk[x]=1;
		}
		if(!parent[y]){
			parent[y] = y;
			rnk[y]=1;
		}
		if(fnd(x)!=fnd(y))
			unite(x,y);
	}
	set<int> s;
	for(auto it = parent.begin();it != parent.end();it++){
		s.insert(it->S);
	}
	//cout << s1.size() << endl;
	cout << s.size()+n-s1.size() << endl;
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