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
int main()
{
	//fast_io;	
	int n,m;
	cin >> n >> m;
	ll a[n];
	FOR(i,0,n-1)
		scanf(LLD,&a[i]);
	int increase = 0;
	FOR(i,0,m-1)
	{
		int t;
		scanf("%d", &t);
		if(t ==1 )
		{
			int v,x;
			scanf("%d%d",&v,&x);
			a[v-1] = x - increase;
		}
		else if(t == 2)
		{
			int y;
			scanf("%d",&y);
			increase += y;
		}
		else if(t ==3)
		{
			int q;
			scanf("%d",&q);
			printf(LLD, a[q-1]+increase);
			printf("\n");
		}
	}
	return 0;
}