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
bitset<100001> visit;
vii adj(100001);
vi dis(100001);
void rset(){
	visit.reset();
	fill(all(dis),0);
	FOR(i,0,100001) adj[i].clear();
}
int n;
void bfs(int x){
	queue<int> q;
	q.push(x);
	visit[x]=1;
	dis[x]=0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		for(auto it = adj[top].begin();it!= adj[top].end();it++){
			if(!visit[*it]){
				q.push(*it);
				visit[*it]=1;
				dis[*it]=1+dis[top];
			}
		}
	}
}
void solve(){
	rset();
	cin >> n;
	FOR(i,0,n-1){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	bfs(0);
	int d = max_element(all(dis))-dis.begin();
	visit.reset();
	fill(all(dis),0);
	bfs(d);
	d = *max_element(all(dis));
	if(d&1) d= d/2 + 1;
	else d = d/2;
	cout << d << endl;
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