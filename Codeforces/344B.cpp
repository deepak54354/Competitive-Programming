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
	vi a(3);
	cin >> a[0] >> a[1] >> a[2];
	int b[3][3] = {0};
	if(a[0]==a[1]&&a[1]==a[2] && a[1]%2 == 1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	else if(a[0]== a[1]&&a[1]==a[2] && a[1]%2 == 0)
	{
		cout << a[0]/2 << " " << a[0]/2 << " " << a[0]/2<< endl;
		return 0;
	}
	while(1)
	{
		int maxi = max_element(a.begin(),a.end()) - a.begin();
		int mini = min_element(a.begin(),a.end()) - a.begin();
		a[mini]--;a[maxi]--;
		b[maxi][mini]++;
		if(a[mini] == 0)
		{
			if(a[3-mini-maxi] == a[maxi])
			{
				b[maxi][3-mini-maxi]+= a[maxi];
				break;
			}
			else
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	cout << b[0][1]+b[1][0] << " " << b[1][2] + b[2][1] << " " << b[0][2] + b[2][0] << endl;
	return 0;
}