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
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	int sum = 0;
	FOR(i,0,n-1)
	{
		cin >> a[i];
		sum += a[i];
	}
	bool flag = sum&1;
	FOR(i,0,n-1)
	{
		if(flag)
		{
			ans += (a[i]&1?1:0);
		}
		else
			ans += (a[i]&1?0:1);
	}
	cout << ans << endl;
  	return 0;
}
