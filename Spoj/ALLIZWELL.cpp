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
char mat[107][107];
vector<bitset<107> > visit(107);
string s = "ALLIZZWELL";// 10 characters
int n,m;
int change[8][2] ={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
int counter = 1;
void dfs(pii p,int i){
	counter = max(i,counter);
	//cout << counter << endl;
	visit[p.F][p.S]=1;
	FOR(j,0,8){
		pii c = make_pair(p.F+change[j][0],p.S+change[j][1]);
		if(c.F <0 || c.F >= n|| c.S <0 ||c.S >=m) continue;
		if(!visit[c.F][c.S] && i < 10 && mat[c.F][c.S] == s[i]){
			dfs(c,i+1);
			//cout << c.F << " " << c.S << " "<< i << endl;
		}
	}
	visit[p.F][p.S]=0;
}
void solve(){
	FOR(i,0,107) visit[i].reset();
	FOR(i,0,107) FOR(j,0,107) mat[i][j] = '.';
	counter = 1;
	cin >> n >> m;
	vector<pii > v;
	FOR(i,0,n){
		FOR(j,0,m){
			cin >> mat[i][j];
			if(mat[i][j]=='A') v.pb(make_pair(i,j));
		}
	}
	//cout << "ji" << endl;
	FOR(i,0,v.size()){
		FOR(j,0,107) visit[j].reset();
		dfs(v[i], 1);
	}
	cout << (counter==10?"YES":"NO") << endl;
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