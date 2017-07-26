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
vector<bitset<101> > visit(101);
char mat[101][101];
pii parent[101][101];
int change[4][4]={{1,0},{0,1},{-1,0},{0,-1}};
void solve(){
	FOR(i,0,101) visit[i].reset();
	FOR(i,0,101) FOR(j,0,101) parent[i][j] = make_pair(-1,-1);
	int n,m;
	cin >> n >> m;
	pii start,end;
	FOR(i,0,n){
		FOR(j,0,m){
			cin >> mat[i][j];
			if(mat[i][j]=='X') visit[i][j]=1;
			else if(mat[i][j]=='M')start=make_pair(i,j);
			else if(mat[i][j]=='*')end=make_pair(i,j);
		}
	}
	int k;
	cin >> k;
	queue<pii > q;
	parent[start.F][start.S]=start;
	q.push(start);
	visit[start.F][start.S]=1;
	bool flag = false;
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		FOR(i,0,4){
			pii c = make_pair(top.F+change[i][0],top.S+change[i][1]);
			if(c.F<0 || c.F >=n || c.S<0||c.S>=m) continue;
			if(!visit[c.F][c.S]){
				parent[c.F][c.S] = (top);
				visit[c.F][c.S]=1;
				if(c==end){
					flag = 1;
					break;
				}
				q.push(c);
			}
		}
		if(flag) break;
	}
	pii s = parent[end.F][end.S];
	int ans = 0;
	flag = 1;
	while(flag){
		if(s==start) flag = false;
		//cout << "s: " << s.F  << " " << s.S<<endl;
		//cout << "parent: " << parent[s.F][s.S].F << " " << parent[s.F][s.S].S << " ";
		int cnt = 0;
		FOR(i,0,4){
			pii comb = make_pair(s.F+change[i][0],s.S+change[i][1]);
			if(comb.F<0||comb.F>=n||comb.S<0||comb.S>=m) continue;
			if(comb==parent[s.F][s.S] || mat[comb.F][comb.S] == 'X') continue;
			else cnt++;
		}
		if(cnt>1){
			//cout << "yes" <<endl;
			ans++;
		}
		s = parent[s.F][s.S];
	}
	cout << (ans==k?"Impressed":"Oops!") << endl;
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