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
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
int main()
{
	fast_io;
	int t,x,y,ex,ey;
	cin >> t >> x >> y >> ex >> ey;
	string s;
	cin >> s;
	int i;
	for(i = 0; i < t; i++)
	{
		int x1 = ex - x;
		int y1 = ey- y;
		if(s[i] == 'N' && y1 > 0)
			y = y+1;
		else if(s[i] == 'S' && y1 < 0)
			y = y-1;
		else if(s[i] == 'E' && x1 >0)
			x = x+1;
		else if(s[i] == 'W' && x1 < 0)
			x-=1;
		if(x1 == 0 && y1 == 0)
			break;
	}  
	if(x != ex || y != ey)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << i << endl;	
	return 0;
}