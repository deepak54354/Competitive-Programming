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
	//ifstream in_file(file.in);
	//ofstream out_file(file.out);
	int n,a[3];
	cin >> n >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	if(a[0] == a[3])
	{
		cout << n/a[0] << endl;
		return 0;
	}
	else if(a[0] == 1 || a[1] == 1 || a[2] == 1)
	{
		cout << n << endl;
		return 0;
	}
	else
	{
		vi ans;
		for(int i = 0; i*a[2] <= n; i++)
		{
			for(int j = 0; i*a[2] + j*a[1] <= n; j++)
			{
				int temp = abs(a[2]*i + a[1]*j - n);
				if(temp%a[0] == 0)
					ans.pb(i+j+temp/a[0]);
			}
		}
		cout << (*max_element(ans.begin(),ans.end())) << endl;
	}
	return 0;
}