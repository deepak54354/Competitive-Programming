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
int a[200], m = 1;
void multiply(int n)
{
	int temp = 0;
	FOR(i,0,m-1)
	{
		int t = a[i]*n + temp;
		a[i] = t%10;
		temp = t/10;
	}
	while(temp >0)
	{
		a[m] = temp%10;
		temp/=10;
		m++;
	}
}
int main()
{
	fast_io;
	int t;
	cin >> t;
	while(t--)
	{
		a[0] = 1;
		FOR(i,1,199)
			a[i] = 0;
		int n;
		m = 1;
		cin >> n;
		FOR(i,2,n)
			multiply(i);
		FORD(i,0,m-1)
			cout << a[i];
		if(t != 0)
			cout << endl;
	}	
	return 0;
}