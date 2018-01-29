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
const int N = 1100; 
vector<string> m(N);
int change[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>> vis(N,vi(N,INT_MAX));
int R,C;
//functions specific to question
void bfs(pii s){
	deque<pii> d;
	d.push_back(s);
	vis[s.F][s.S]=0;
	while(!d.empty()){
		pii top = d.front();
		d.pop_front();
		FOR(i,0,4){
			pii curr = {top.F+change[i][0],top.S+change[i][1]};
			if(curr.F >= R or curr.F <0 or curr.S >=C or curr.S <0){
				continue;
			}
			if(vis[top.F][top.S]+(m[top.F][top.S]!=m[curr.F][curr.S]) >= vis[curr.F][curr.S]){
				continue;
			}
			if(m[top.F][top.S]==m[curr.F][curr.S]){
				d.push_front(curr);
				vis[curr.F][curr.S]=vis[top.F][top.S];
			}
			else{
				d.push_back(curr);
				vis[curr.F][curr.S]=1+vis[top.F][top.S];
			}
			//cout << curr.F << " " << curr.S << " " << vis[curr.F][curr.S] << '\n';
		}
	}
}
// solution here 
void solve(){
	cin >> R >> C;
	FOR(i,0,R){
		cin >> m[i];
	}
	FOR(i,0,N) FOR(j,0,N) vis[i][j]=INT_MAX;
	bfs({0,0});
	cout << vis[R-1][C-1]<< '\n';
}

//driver function
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