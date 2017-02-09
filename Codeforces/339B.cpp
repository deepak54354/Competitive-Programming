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
int main()
{
	int n, m;
	cin >> n >> m;
	vi a(m);
	FOR(i,0,m-1)
		cin >> a[i];

	int c = 1;
	int t;
	ll steps = 0;
	FOR(i,0,m-1)
	{
		t = a[i];
		if(c <=t)
		{
			steps += (t-c);
			c = t;
		}
		else
		{
			steps += (n-(c-t));
			c = t;
		}
	}
	cout << steps << endl;
  	return 0;
}
