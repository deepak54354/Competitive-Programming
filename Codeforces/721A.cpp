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
	string s;
	cin >> n;
	cin >> s;
	int groups = 0;
	vi col;
	FOR(i,0,n-1)
	{
		if(s[i] == 'B')
		{
			if(i == 0 || s[i-1] == 'W')
			{
				groups++;
				col.pb(1);
			}
			else
			{
				col[groups-1]++;
			}
		}
	}
	cout << groups << endl;
	FOR(i,0,groups -1)
	{
		if(i < groups-1)
			cout << col[i] << " ";
		else
			cout << col[i] << endl;
	}
  	return 0;
}
