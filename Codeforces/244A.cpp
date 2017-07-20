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

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,k;
	cin >> n >> k;
	int c[n*k] = {0};
	vector <vector <int> > v(k);
	FOR(i,0,k-1)
	{
		int a;
		cin >> a;
		v[i].pb(a);
		c[a-1] = 1;
	}
	int j = 0;
	FOR(i,0,k-1)
	{
		int count = 0;
		while(count < n-1 && j < n*k)
		{
			if(c[j] == 0)
			{
				v[i].pb(j+1);
				c[j] = 1;
				count++;
			}
			j++;
		}
	}
	FOR(i,0,k-1)
	{
		FOR(j,0,n-1)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}