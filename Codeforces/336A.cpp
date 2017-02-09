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
	pair<ll,ll> a,b;
	ll c,d;
	cin >> c >> d;
	ll sum = abs(c) + abs(d);
	a = make_pair(0,sum);
	b  = make_pair(sum,0);
	if(c < 0)
	{
		if(d > 0)
			b.F *= -1;
		else
		{
			b.F *= -1;
			a.S *= -1;
		}
	}
	else if(d < 0)
		a.S *= -1;
	if(b.F < 0)
		cout << b.F << " " << b.S << " " << a.F<< " " << a.S << endl;
	else
		cout << a.F << " " << a.S << " " << b.F << " " << b.S << endl;
  	return 0;
}
