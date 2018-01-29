/****************************************************************************
*					Author: Deepak Nathani									*
*					hackerrank:- savager									*
*					codeforces:- deepak54354								*
*					Spoj:- deepak54354										*
*					Github:- deeplearning10									*
*****************************************************************************/					


#include <bits/stdc++.h>
using namespace std;

// Math
#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
#define SQR(n) ((n)*(n))

// memory 
#define MEM(a,val) memset(a,val,sizeof(a))

// Data types and related macros
#define ll long long
#define ul unsigned long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SS stringstream

//loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

// I/O
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

// useful functions
template <typename T>
T mod(T a, T b) // calculates a%b, not remainder
{
	T ans;
	if(b == 0)
		return -1;
	else
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	return ans;
}

ll fast_exp(ll base,ll n, ll M)
{
	ll ans = 1;
	while(n)
	{
		if(n%2==1)
		ans = (ans*base)%M;
		base = (base*base)%M;
		n = n>>1;
	}
	return ans%M;
}

//splits a string according to a given delimiter
template<typename Out>
void split(const string &s, char delim, Out result) {
	SS ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}
//function ends

//declare question related constants here 
const int N = 100010;
vii g(N);
vii gr(N);
list<int> order;
bool vis[N];
vi curr;
int ans[N];
//functions specific to question
void dfs1(int u){
	vis[u]=1;
	for(auto i : g[u]){
		if(!vis[i]) dfs1(i);
	}
	order.push_front(u);
}
void dfs2(int u){
	vis[u]=1;
	curr.pb(u);
	for(auto i : gr[u]){
		if(!vis[i]) dfs2(i);
	}
}

// solution here 
void solve(){
	int n,m;
	cin >> n >> m;
	while(m--){
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
		gr[y].pb(x);
	}
	for (int i = 1; i <=n; ++i)
	{
		/* code */
		if(!vis[i]) dfs1(i);
	}
	FOR(i,0,N) vis[i]=0;
	for(auto i : order){
		if(!vis[i]){
			curr.clear();
			dfs2(i);
			if(curr.size()>1){
				for(auto j : curr){
					ans[j]=1;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		/* code */
		cout << ans[i] << " ";
	}
	cout << '\n';
}

//driver function
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