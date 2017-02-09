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
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	double a,b,c,d;
	cin >> a >> b >> c >> d;
	int num,den;
	double temp = a/b;
	double temp1 = c/d;
	if(abs(temp-temp1) <=eps)
	{
		cout << "0/1" << endl;
		return 0;
	}
	else if(temp1 - temp > eps)
	{
		num = b*c-a*d;
		den = b*c;
	}
	else if(temp - temp1 > eps)
	{
		num = a*d-b*c;
		den = a*d;
	}
	int gd = __gcd(num,den);
	num = num/gd;
	den = den/gd;
	cout << num<<"/"<<den << endl;
	return 0;
}