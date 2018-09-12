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
const int N = 400010;
vector<bool> used(N,0);
int v[N];
int from[N];
int to[N];
int cnt = -1;
vii adj(N);

ll t[N<<3];
int lazy[N<<3];

int color[N];
//functions specific to question

void dfs(int i){
	used[i]=true;
	v[++cnt]=i;
	from[i]=cnt;

	for(auto j : adj[i]){
		if(!used[j]) dfs(j);
	}
	to[i]=cnt;
}

void build(int node, int st, int end){
	if(st==end){
		t[node]=(1ll<<color[v[st]]);
		//cout << color[v[st]] << " " << t[node] << endl;
		//cout << "node: " << node << " v[st]: " << v[st]  << " count: "<< __builtin_popcountll(t[node]) << '\n';
		return;
	}
	else {
		int mid = (st+end)>>1;
		build(node<<1,st,mid);
		build(node<<1|1,mid+1,end);
		t[node]=t[node<<1]|t[node<<1|1];
		//cout << "node: " << node << " count: " << __builtin_popcountll(t[node]) << '\n';
	}
	
}
void update(int node,int st, int end, int l, int r, int c){
	if(lazy[node]){
		t[node]=1ll<<lazy[node];
		if(st!=end)
		{
			lazy[node<<1]=lazy[node<<1|1]=lazy[node];
		}
		lazy[node]=0;
	}
	if(l>end or r <st or st >end){
		return;
	}
	if(l<=st and r >=end){
		t[node]=1ll << c;
		if(st!=end)
			lazy[node<<1]=lazy[node<<1|1]=c;
		return;
	}
	int mid = (st+end)>>1;
	update(node<<1,st,mid,l,r,c);
	update(node<<1|1,mid+1,end,l,r,c);
	t[node]=t[node<<1]|t[node<<1|1];
}
ll query(int node,int st,int end, int l ,int r){
	if(lazy[node]!=0){
		t[node]=1ll<<lazy[node];
		if(st!=end)
			lazy[node<<1]=lazy[node<<1|1] = lazy[node];
		lazy[node]=0;
	}
	if(l>end or r <st or st>end){
		return 0ll;
	}
	if(l<=st and r >=end){
		return t[node];
	}
	int mid = (st+end)>>1;
	ll q1 = query(node<<1,st,mid,l,r);
	ll q2 = query(node<<1|1,mid+1,end,l,r);
	return q1|q2;
}
// solution here 
void solve(){
	int n,m;
	cin >> n >> m;
	FOR(i,1,n+1){
		cin >> color[i];
	}
	FOR(i,0,n-1){
		int x,y;
		cin >> x >>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1);
	build(1,0,n-1);
	/*for(int i = 0; i < n ; i ++){
		cout << v[i] << endl;
	}
	for(int i=1; i <=n; i++){
		cout <<"i: " << i << " "<< from[i] << ' ' << to[i] << endl;
	}*/
	while(m--){
		/*cout << "New tree" << endl;
		for(int i=1; i< 14; i++){
			cout <<"i: " << i  << " "<< __builtin_popcountll(t[i]) << endl;
		}*/
		int i;
		cin >> i;
		if(i==1){
			int v,c;
			cin >> v >> c;
			update(1,0,n-1,from[v],to[v],c);
		}
		else{
			int v;
			cin >> v;
			ll q = query(1,0,n-1,from[v],to[v]);
			cout << __builtin_popcountll(q) << '\n';
		}
	}
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