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
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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
int n,s,t;
int g,seed,p;
int *R, *dp;
bool* used;
void bfs(int s, int t){
	queue<int> q;
	q.push(s);
	dp[s] = 0;
	used[s] = true;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(R[u] >=n/2){
			dp[t] = dp[u]+1;
			return;
		}
		FOR(i,1,R[u]){
			if(u == t) return;
			int v,w;
			v = mod(u-i,n);w = mod(u+i,n);
			if(!used[v]){
				q.push(v);
				dp[v] = dp[u]+1;
				used[v] = true;
				if(min(abs(v-t),n-abs(v-t))<=R[v]){
					dp[t] = dp[v]+1;
					return;
				}
			}
			if(!used[w]){
				q.push(w);
				dp[w] = dp[u]+1;
				used[w] = true;
				if(min(abs(w-t),n-abs(w-t))<=R[w]){
					dp[t] = dp[w]+1;
					return;
				}
			}
		}
	}
	return;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> s >> t;
	R = new int[n];
	dp = new int[n];
	used = new bool[n];
	cin >> R[0] >> g >> seed >> p;
	FOR(i,0,n-1) 
	{
		used[i] = false;
		dp[i] = -1;
	}
	FOR(i,1,n-1)
		R[i] = mod(R[i-1]*g+seed,p);
	bfs(s,t);
	//FOR(i,0,n-1) cout << dp[i] << endl;
	cout << dp[t] << endl;
	return 0;
}