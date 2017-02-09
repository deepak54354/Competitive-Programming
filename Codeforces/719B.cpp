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
	cin >>n;
	string s;
	cin >> s;
	int mr = 0,mb = 0;
	//for rbrb, even-r and odd-b
	//for brbr, even-b and odd-r
	FOR(i,0,s.size()-1)
	{
		if(i%2 == 0)
		{
			if(s[i] == 'b')
				mr++;
		}
		else
			if(s[i] == 'r')
				mb++;
	}
	int x = max(mb,mr);
	mb = mr = 0;
	FOR(i,0,s.size()-1)
	{
		if(i%2 == 0)
		{
			if(s[i] == 'r')
				mb++;
		}
		
		else
			if(s[i] == 'b')
				mr++;
	}
	int y = max(mb,mr);
	int count = min(x,y);
	cout << count << endl;
  	return 0;
}
		