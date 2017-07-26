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
#define F firsat
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
int steps[10][10][10][10];
bool visit[10][10][10][10]={0};
int change[8][4]= {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1},{-1,0,0,0},{0,-1,0,0},{0,0,-1,0},{0,0,0,-1}};
bool push_q(vi a){

	return visit[a[0]][a[1]][a[2]][a[3]];
}

int bfs(vi start,vi end){
	queue<vi > q;
	q.push(start);
	visit[start[0]][start[1]][start[2]][start[3]] = 1;
	steps[start[0]][start[1]][start[2]][start[3]] = 0;
	while(!q.empty()){
		vi t = q.front();
		q.pop();
		//cout <<1 << endl;
		visit[t[0]][t[1]][t[2]][t[3]] = true;
		int st = steps[t[0]][t[1]][t[2]][t[3]];
		//cout << t[0] << " " << t[1] << " " << t[2] <<" " << t[3] << endl;
		FOR(i,0,8){
			vi c;
			FOR(j,0,4){
				c.pb(t[j]+change[i][j]);
				if(c[j]<0) c[j]=9;
				else if(c[j]>9) c[j]=0;
			}
			if(!push_q(c)){
				if(c[0]==end[0] && c[1]==end[1] && c[2]==end[2] && c[3]==end[3]) return 1+st;
				q.push(c);
				visit[c[0]][c[1]][c[2]][c[3]] = true;
				steps[c[0]][c[1]][c[2]][c[3]] = 1+st;
			}
		}
	}
	return -1;
}

void solve(){
	vi start(4),end(4);
	FOR(i,0,10) FOR(j,0,10) FOR(k,0,10) FOR(l,0,10) visit[i][j][k][l]=false;
	FOR(i,0,10) FOR(j,0,10) FOR(k,0,10) FOR(l,0,10) steps[i][j][k][l]=0;
	FOR(i,0,4) cin >> start[i];
	FOR(i,0,4) cin >> end[i];
	int q;
	cin >> q;
	while(q--){
		int c[4];
		FOR(i,0,4) cin >> c[i];
		visit[c[0]][c[1]][c[2]][c[3]]=1;
	}
	cout << bfs(start,end)<< endl;
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