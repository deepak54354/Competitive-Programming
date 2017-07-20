#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX (long long)(1e15)
#define MIN int(-1e9)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<ll,ll>
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
/*struct comp{
	bool operator()(const pii& a, const pii& b){
		return a.S < b.S;
	}
};*/
void dijkstra(vector<vector<pii> > graph, int n){
	multiset<pii > q;
	vector<ll> key(n+1,MAX);
	key[1] = 0;
	bool used[n+1]={false};
	int parent[n+1];
	FOR(i,0,n+1) parent[i] = -1;
	q.insert(make_pair(0,1));
	while(!q.empty()){
		auto it = q.begin();
		int u = (*it).S;
		// cout << u << endl;
		q.erase(it);
		used[u] = true;
		//cout << u  << "-> ";
		FOR(i,0,graph[u].size()){
			int v = graph[u][i].S;
			//cout << v << " ";
			int update = graph[u][i].F;
			if(key[u]+update < key[v]){
				it = q.find(make_pair(key[v],v));
				if(it!= q.end()) q.erase(it);
				key[v] = key[u]+update;
				q.insert(make_pair(key[v],v));
				parent[v] = u;
			}
		}
		//cout << endl;
	}
	//cout << "yolo";
	if(parent[n] == -1){
		cout << -1 << endl;
		return;
	}
	int t = n;
	vi ans;
	while(parent[t] != -1){
		ans.pb(parent[t]);
		t = parent[t];
	}
	FORD(i,0,ans.size()-1){
		cout << ans[i] << " ";
	}
	cout << n << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,m;
	cin >> n >> m;
	vector<vector<pii> > adj(n+1);
	FOR(i,0,m){
		int x,y;
		ll z;
		cin >> x >> y >> z;
		adj[x].pb(make_pair(z,y));
		adj[y].pb(make_pair(z,x));
	}
	dijkstra(adj, n);
	return 0;
}