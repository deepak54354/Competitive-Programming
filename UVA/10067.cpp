#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
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

typedef struct node{
	int x1,x2,x3,x4;
	int steps;
}node;

int visit[10][10][10][10] = {0};

int change[8][4] = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};

int push_queue(node n){
	if(visit[n.x1][n.x2][n.x3][n.x4] == -1 || visit[n.x1][n.x2][n.x3][n.x4] == 1) return 0;
	else
		return 1;
}
int bfs(node start, node end){
	queue<node> q;
	q.push(start);
	if(visit[start.x1][start.x2][start.x3][start.x4] == -1 || visit[end.x1][end.x2][end.x3][end.x4] == -1)
		return -1;
	int steps = 0;
	visit[start.x1][start.x2][start.x3][start.x4] = 1;
	while(!q.empty()){
		node top = q.front();
		FOR(i,0,7){
			node current;
			current.x1 = top.x1+change[i][0];current.x2 = top.x2+change[i][1];
			current.x3 = top.x3+change[i][2];current.x4 = top.x4+change[i][3];
			if(current.x1 > 9 || current.x2 > 9 || current.x3 > 9 || current.x4 > 9 || current.x1 < 0 ||
				current.x2 < 0 || current.x3 < 0 || current.x4 < 0)
				continue;
			else if(push_queue(current) == 1){				
				current.steps = top.steps + 1;
				visit[current.x1][current.x2][current.x3][current.x4] = 1;
				q.push(current);
			}
			if(current.x1 == end.x1 && current.x2 == end.x2 && current.x3 == end.x3 && current.x4 == end.x4){
				return current.steps;
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--)
	{
		FOR(i,0,9) FOR(j,0,9) FOR(k,0,9) FOR(w,0,9) visit[i][j][k][w] = 0;
		node start,end;
		cin >> start.x1 >> start.x2 >> start.x3 >> start.x4;start.steps = 0;
		cin >> end.x1 >> end.x2 >> end.x3 >> end.x4;
		int m;
		cin >> m;
		FOR(i,0,m-1){
			int x,y,z,w;
			cin >> x >> y >> z >> w;
			visit[x][y][z][w] = -1;
		}
		cout << bfs(start,end) << endl;
	}
	return 0;
}