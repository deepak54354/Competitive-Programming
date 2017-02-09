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
	int t;
	cin >> t;
	while(t--)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x = x2-x1;
		int y = y2-y1;
		if(x == 0 && y >0)
			cout << "up" << endl;
		else if(x == 0 && y < 0)
			cout << "down" << endl;
		else if(y == 0 && x >0)
			cout << "right" << endl;
		else if(y == 0 && x < 0)
			cout << "left" << endl;
		else
			cout << "sad" << endl;
	}	
	return 0;
}