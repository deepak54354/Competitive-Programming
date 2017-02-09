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
int main()
{
	fast_io;
	int n;
	cin >> n;
	int sum = 0;
	int d,x = 0,y = 0;
	FOR(i,0,n-1)
	{
		cin >> d;
		if(d == 100) x++;
		else y++;
	}
	sum = 100*x + 200*y;
	if(sum%200 || n==1)
		cout << "NO" << endl;
	else
	{
		int half = sum/2;
		bool flag = false;
		FOR(i,0,y)
		{
			if(200*i <= half && half-200*i <= x*100) flag = true;
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
  	return 0;
}
