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
	int r,c;
	vector< vector<char> > cake;
	cin >> r >> c;
	vector<char> temp(c);
	FOR(i,0,r-1)
	{
		FOR(j,0,c-1)
			cin >> temp[j];
		cake.pb(temp);
	}
	int count = 0;
	FOR(i,0,r-1)
	{
		if(find(cake[i].begin(),cake[i].end(), 'S') == cake[i].end())
		{
			FOR(j,0,c-1)
			{
				if(cake[i][j] == '.')
				{
					count++;
					cake[i][j] = '0';
				}
			}
		}
	}
	FOR(i,0,c-1)
	{
		bool flag = false;
		FOR(j,0,r-1)
		{
			if(cake[j][i] == 'S')
				flag = true;
		}
		if(!flag)
		{
			FOR(j,0,r-1)
			{
				if(cake[j][i] == '.')
				{
					count++;
					cake[j][i] = '0';
				}
			}
		}
	}
	cout << count << endl;
  	return 0;
}
