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
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define fast_io ios_base::sync_with_stdio(false)
#define N 100009
int sq = sqrt(100009);
int ans[N], c1[N],answer = 0;
ll v[N];
struct node
{
	ll R,L,i;
}q[N];

bool cmp(node &a, node &b)
{
	int c = a.L/sq;
	int d = b.L/sq;
	if(c != d) return a.L < b.L;
	return a.R < b.R;
}

void add(int p)
{
	c1[p]++;
	if(c1[p] == v[p]) answer++;
}

void remove(int p)
{
	c1[p]--;
	if(c1[p] == v[p]-1) answer--;
}
int main()
{
	fast_io;
	FOR(i,0,N-1)
		c1[i] = 0;
	int n,m;
	cin >> n >> m;
	FOR(i,0,n-1)
		cin >> v[i];
	FOR(i,0,m-1)
	{
		cin >> q[i].L >> q[i].R;
		q[i].L--;q[i].R--;
		q[i].i = i;
	}
	sort(q,q+m,cmp);
	int currentL, currentR;
	currentR = currentL = 0;
	FOR(i,0,m-1)
	{
		while(currentL > q[i].L)
		{
			add(currentL-1);
			currentL--;
		}
		while(currentR <= q[i].R)
		{
			add(currentR);
			currentR++;
		}
		while(currentL < q[i].L)
		{
			remove(currentL);
			currentL++;
		}
		while(currentR > q[i].R+1)
		{
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}
	FOR(i,0,m-1)
		cout << ans[i] << endl;
  	return 0;
}
