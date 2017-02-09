#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F firs
#define S second
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
int n,m;
void replace(int num1, int num2, int* arr)
{
	FOR(i,0,m-1)
	{
		if(arr[i] == num1)
			arr[i] = num2;
	}
	return;
}
int main()
{
	fast_io;
	cin >> n >> m;
	int c[m];
	MEM(c,-1);
	int counter = 0;
	int temp;
	int ans = 0;
	FOR(l,0,n-1)
	{
		int x;
		cin >> x;
		if(!x)
		{
			ans++;
			continue;
		}
		bool flag = false;
		vi v;
		FOR(i,0,x-1)
		{
			int y;
			cin >> y;
			v.pb(y);
			if(flag)
				continue;
			if(c[y-1] != -1)
			{
				temp = c[y-1];
				flag = true;
			}
		}
		if(!flag)
		{
			temp = counter;
			counter++;
		}
		FOR(j,0,v.size()-1)
		{
			if(c[v[j]-1] == -1)
				c[v[j]-1] = temp;
			else if(c[v[j]-1] != temp)
				replace(c[v[j]-1],temp, c);
		}
	}
	set<int> s;
	FOR(i,0,m-1)
	{
		if(c[i] != -1)
			s.insert(c[i]);
	}
	if(s.size()!=0)
		ans += s.size()-1;
	cout << ans << endl;
  	return 0;
}