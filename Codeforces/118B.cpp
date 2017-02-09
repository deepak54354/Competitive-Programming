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
	cin >> n;
	int ans[2*n+1][2*n+1];
	FOR(i,0,2*n)
		FOR(j,0,2*n)
			ans[i][j] = -1;
	int i = 0;
	int maxi = n;
	for(int j = n; j>=0; j--,i++,maxi--)
	{
		int temp = 0;
		int m = i;
		while(temp < maxi)
		{
			ans[m][j] = temp;
			ans[m][2*n-j] = temp;
			m++;
			temp++;
		}
		while(temp >= 0)
		{
			ans[m][j] = temp;
			ans[m][2*n-j] = temp;
			m++;
			temp--;
		}
	}
	FOR(x,0,2*n)
	{
		FOR(y,0,2*n)
		{
			if(ans[x][y] == -1)
			{
				if(x <= n)
				{
					if(y < x+n)
						cout << " " << " "; 
				}
				else
				{
					if(y < 3*n-x)
						cout << " " << " ";
				}
			}
			else if(ans[x][y]!=-1)
			{
				cout << ans[x][y];
				if(y < 2*n && ans[x][y+1] != -1)
					cout << " ";
			}
		}
		cout << endl;
	}
  	return 0;
}
