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
	int n,m;
	cin >> n >> m;
	int per[n] = {0};
	int a[m][3];
	FOR(i,0,m-1)
	{
		FOR(j,0,2)
			cin >> a[i][j];
	}
	FOR(i,0,2)
	{
		per[a[0][i]-1] = i+1;
	}	
	FOR(j,1,m-1)
	{
		if(per[a[j][0]-1] == 0 && per[a[j][1]-1] == 0 && per[a[j][2]-1] == 0)
		{
			FOR(i,0,2)
			{
				per[a[j][i]-1] = per[a[0][i]-1];
			}
		}
		else
		{
			int st;
			bool flag = true;
			FOR(i,0,2)
			{
				if(per[a[j][i]-1] != 0)
					st = i;
			}
			if(	per[a[j-1][st]-1] == per[a[j][st]-1])
			{
				FOR(i,0,2)
					per[a[j][i]-1] = per[a[j-1][i]-1];
			}
			else
			{
				FOR(i,0,2)
				{
					if(per[a[j][i]-1] == 0 && per[a[j-1][i]-1] == per[a[j][st]-1])
					{
						per[a[j][i]-1] = per[a[j-1][st]-1];
						flag = false;
					}
					else if(per[a[j][i]-1] == 0)
					{
						per[a[j][i]-1] = per[a[j-1][i]-1];
					}
				}
			}
		}
	}
	FOR(i,0,n-1)
	{
		cout << per[i] << " ";
	}
	cout << endl;
	return 0;
}