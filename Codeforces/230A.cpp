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
	int s,n;
	cin >> s >> n;
	vector<pair<int,int> > a(n);
	FOR(i,0,n-1)
	{
		cin >> a[i].F;
		cin >> a[i].S;
	}
	sort(a.begin(),a.end());
	FOR(i,0,n-1)
	{
		if(s > a[i].F)
		{
			s+=a[i].S;
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
  	return 0;
}
