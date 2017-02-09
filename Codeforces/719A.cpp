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
	int a[n];
	FOR(i,0,n-1)
	{
		cin >> a[i];
	}
	if(a[n-1]!= 15)
	{
		if(a[n-1] == 0)
			cout << "UP" << endl;
		else if(n==1)
			cout << -1 << endl;
		else if(a[n-1] > a[n-2])
			cout << "UP" << endl;
		else
			cout << "DOWN" << endl; 
	}
	else
	{
			cout << "DOWN" << endl;
	}
  	return 0;
}
