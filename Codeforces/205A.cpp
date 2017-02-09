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
	vi cities(n);
	FOR(i,0,n-1)
		cin >> cities[i];
	int min = 0;
	bool flag = true; // true = we can print minimum/nomore than one minimum
	FOR(i,1,n-1)
	{
		if(cities[i] < cities[min])
		{
			min = i;
			flag = true;
		}
		else if(cities[i] == cities[min])
		{
			flag = false;
		}
	}
	if(flag)
		cout << min+1 << endl;
	else
		cout << "Still Rozdil" << endl;
  	return 0;
}
