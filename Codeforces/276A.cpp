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
	ll k,f,t,maxi = -1000000001;
	cin >> n >> k;
	ll temp = 0;
	FOR(i,0,n-1)
	{
		cin >> f >> t;
		temp = f;
		if(t > k)
			temp -= (t-k);

		if(temp > maxi)
			maxi = temp;
	}
	cout << maxi << endl;
  	return 0;
}
