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
	int n,m;
	cin >> n >> m;
	vi tv(n);
	FOR(i,0,n-1)
		cin >> tv[i];

	sort(tv.begin(),tv.end());
	ll ans = 0;
	FOR(i,0,m-1)
	{
		if(tv[i] < 0)
			ans += abs(tv[i]);
		else
			break;
	}
	cout << ans << endl;
  	return 0;
}
