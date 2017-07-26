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
vector<bool > visit(101,0);
vector<int> direct(101,0);
vector<int> dist(101,0);
void bfs(){
	visit[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int top = q.front();
		q.pop();
		FOR(i,1,7){
			if(top+i>100)continue;
			int current=direct[top+i];
			if(visit[current])continue;
			else{
				visit[current]=1;
				q.push(current);
				dist[current]=1+dist[top];
			}
		}
	}
}
void solve(){
	FOR(i,0,101){
		visit[i]=0;
		direct[i]=i;
		dist[i]=-1;
	}
	dist[1]=0;
	int n,m;
	cin >> n;
	while(n--){
		int x,y;
		cin >> x >> y;
		direct[x]=y;
	}
	cin >> m;
	while(m--){
		int x,y;
		cin >> x >> y;
		direct[x]=y;
	}
	bfs();
	cout << dist[100] << endl;
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