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
	int x,y,a,b;
	int x1,y1,a1,b1;
	cin >> x >> y >> a >> b;
	if(x != a && y != b && abs(x-a) != abs(y-b))
	{
		cout << -1 << endl;
		return 0;
	}
	else if(x == a)
	{
		int dis = abs(y-b);
		x1 = x +dis;
		y1 = y;
		a1 = a+dis;
		b1 = b;
	}
	else if(y == b)
	{
		int dis = abs(x-a);
		x1 = x;
		y1 = y+dis;
		a1 = a;
		b1 = b+dis; 
	}
	else
	{
		x1 = x;
		y1 = b;
		a1 = a;
		b1 = y;
	}
	cout << x1 << " " << y1 << " " << a1 << " " <<  b1 << endl;
  	return 0;
}
