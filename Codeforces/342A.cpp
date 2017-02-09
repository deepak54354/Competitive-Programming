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
#define FOR(i,c,b) for(int i = c; i <= b; i++)
#define FORD(i,c,b) for(int i = c; i >= a; i--)
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
	fast_io;
	int n;
	cin >> n;
	int a[7];
	MEM(a,0);
	int x;
	vi v;
	FOR(i,0,n-1)
	{
		cin >> x;
		a[x-1]++;
	}
	if(a[4] > 0 || a[6] > 0)
		cout << -1 << endl;
	else if(a[0] != (n/3))
		cout << -1 << endl;
	//bool flag = true;
	else
	{
		while(a[0])
		{
			v.pb(1);
			if(a[1] > 0)
			{
				v.pb(2);
				if(a[3] > 0)
				{
					v.pb(4);
					a[3]--;
				} 
				else if(a[5] > 0)
				{
					v.pb(6);
					a[5]--;
				}
				else
				{
					cout << -1 << endl;
					return 0;
				}
				a[1]--;
			}
			else if(a[2] > 0)
			{
				v.pb(3);
				if(a[5] > 0)
				{
					v.pb(6);
					a[5]--;
				}
				else
				{
					cout << -1 << endl;
					return 0;
				}
				a[3]--;
			}
			else
			{
				cout << -1 << endl;
				return 0;
			}
			a[0]--;
		}
		for(int i = 0; i+2 < n; i += 3)
		{
			cout << v[i] << " " << v[i+1] << " " << v[i+2] << endl;
		}
	}
  	return 0;
}
