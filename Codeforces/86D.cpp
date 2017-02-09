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
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
#define N 200010
int sq = sqrt(20010);
int c[1000010], v[N];
ll answer = 0,ans[N];
struct node
{
	int L,R,i;
}q[N];
bool cmp(node &a, node &b)
{
	int c= a.L/sq;
	int d = b.L/sq;
	if(c!= d) return a.L < b.L;
	return a.R < b.R;
}
void add(int p)
{
	//int K = c[v[p]];
	c[v[p]]++;
	answer += (2*c[v[p]]-1)*v[p];
}

void remove(int p)
{
	c[v[p]]--;
	answer -= (2*c[v[p]]+1)*v[p];
}

int main()
{
	//fast_io;
	int n,m;
	//MEM(c,0);
	scanf("%d%d", &n, &m);
	FOR(i,0,n-1)
		scanf("%d",&v[i]);
	FOR(i,0,m-1)
	{
		scanf("%d%d",&q[i].L,&q[i].R);
		q[i].L--;q[i].R--;
		q[i].i = i;
	}
	sort(q,q+m,cmp);
	int currentR, currentL;
	currentL = currentR = 0;
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
		while(currentR > q[i].R+1)
		{
			remove(currentR-1);
			currentR--;
		}
		while(currentL < q[i].L)
		{
			remove(currentL);
			currentL++;
		}
		ans[q[i].i] = answer;
	}
	FOR(i,0,m-1)
	{
		printf(LLD, ans[i]);
		printf("\n");
	}
	return 0;
}
