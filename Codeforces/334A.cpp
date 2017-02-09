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
	deque<int> Candy;
	FOR(i,0,SQR(n)-1)
	{
		Candy.pb(i+1);
	}
	int can = n >> 1;
	FOR(i,0,n-1)
	{
		FOR(j,0,can-1)
		{
			cout << Candy.front() << " " << Candy.back() << " ";
			Candy.pop_front();
			Candy.pop_back();
		}
		cout << endl;
	}
  	return 0;
}
