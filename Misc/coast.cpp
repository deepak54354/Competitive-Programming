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
int change[4][4]={{1,0},{0,1},{-1,0},{0,-1}};
ll length=0;
//bool cnt[1001][1001]={false};
char visit[1010][1010];
int n,m;
void dfs(pii p){
	visit[p.F][p.S]='a';
	FOR(i,0,4){
		pii c = make_pair(p.F+change[i][0],p.S+change[i][1]);
		if(c.F<0 || c.F>n+1||c.S<0||c.S>m+1)
			continue;
		if(visit[c.F][c.S]=='1'){
			length++;
			//cout << p.F << " " << p.S << endl;
		}
		else if(visit[c.F][c.S]=='0'){
			dfs(c);
		}
	}
}
void solve(){
	cin >> n >> m;
	FOR(i,1,n+1){
		FOR(j,1,m+1){

			cin >> visit[i][j];
		}
	}
	FOR(i,1,1008){
			visit[i][0]=visit[0][i]=visit[n+1][i]=visit[i][m+1]='0';
	}
	dfs(make_pair(0,0));
	cout << length << endl;
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