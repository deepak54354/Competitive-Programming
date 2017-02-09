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

bool func(int i,int j)
{
	return i > j;
}
int main()
{
	int n;
	cin >> n;
	vi a(n),b_sort(n);
	FOR(i,0,n-1)
		cin >> a[i];
	b_sort = a;
	sort(b_sort.begin(),b_sort.end(),func);
	int low,up,maxi,mini;
	maxi = b_sort[0];
	mini = b_sort[n-1];
	FORD(i,0,n-1)
	{
		if(a[i] == mini)
		{
			up = i;
			break;
		}
	}
	FOR(i,0,n-1)
	{
		if(a[i] == maxi)
		{
			low = i;
			break;
		}
	}
	int ans = low + abs(up-n+1);
	if(up < low)
		ans--;
	cout << ans << endl;
  	return 0;
}
