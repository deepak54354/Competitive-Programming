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
vi dis(10001,0);
vector<vector<pii > > adj(10001);
bitset<10007> visit;
void bfs(int x){
	queue<int> q;
	q.push(x);
	dis[x]=0;
	visit[x]=1;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		int d = dis[top];
		for(auto it = adj[top].begin();it!=adj[top].end();it++){
			pii c = *it;
			if(!visit[c.F]){
				q.push(c.F);
				dis[c.F] = c.S+d;
				visit[c.F]=1;
			}
		}
	}
}
void solve(){
	int n;
	cin >> n;
	FOR(i,0,n-1){
		int x,y;
		cin >> x >> y;
		adj[x].pb(make_pair(y,1));
		adj[y].pb(make_pair(x,1));
	}
	bfs(1);
	int d = max_element(all(dis))-dis.begin();
	FOR(i,0,10001) dis[i]=0;
	visit.reset();
	bfs(d);
	cout << *max_element(all(dis)) << endl;
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