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
int a[100010];
int *c = new int[100010];
int ans = 0;
void add(int p)
{
	c[a[p]]++;
	if(c[a[p]] == 1) ans++;
}
void remove(int p)
{
	c[a[p]]--;
	if(c[a[p]] == 0) ans--;
}
struct node
{
	int L,i;
}q[100010];
int an[100010];
bool cmp(const node &a, const node &b)
{
	return a.L < b.L;
}
int main()
{
	//fast_io;
	int n,m;
	FOR(i,0,100009)
		c[i] = 0;
	scanf("%d%d", &n,&m);
	FOR(i,0,n-1)
		scanf("%d", &a[i]);
	FOR(i,0,m-1)
	{
		scanf("%d",&q[i].L);
		q[i].L--;q[i].i = i;
	}
	sort(q,q+m,cmp);
	int currentL = 0,currentR = 0;
	FOR(i,0,m-1)
	{
		int L = q[i].L;
		while(currentR <= n-1)
		{
			add(currentR);
			currentR++;
		}
		while(currentL < L)
		{
			remove(currentL);
			currentL++;
		}
		an[q[i].i] = ans;
	}
	FOR(i,0,m-1)
		printf("%d\n", an[i]);
	return 0;
}