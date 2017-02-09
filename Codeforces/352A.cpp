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
	int n5 = 0,n0 = 0;
	int n;
	cin >> n;
	int x;
	FOR(i,0,n-1)
	{
		cin >> x;
		if(x == 5)
			n5++;
		else
			n0++;
	}
	string ans = "";
	if(n0 == 0)
		cout << -1 << endl;
	else if(n5/9 == 0)
		cout << 0 << endl;
	else if((n5/9) >= 1)
	{
		int temp = n5 - (n5%9);
		FOR(i,0,temp-1)
		{
			ans += "5";
		}
		FOR(j,0,n0-1)
			ans += "0";
		cout << ans << endl;
	}
  	return 0;
}
