#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define MEM(a,val) memset(a,val,sizeof(a))
//vector
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
//Extra
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
bool check(ll n, string s)
{
	ll ls = s.size();
	ll temp = n;
	bool flag = 0;
	int i = ls-1;
	while(n)
	{
		int t = n%10;
		if(i < 0)
		{
			flag = ((t%2)?0:1);
		}
		else if(s[i] == 0)
		{
			flag = ((t%2)?0:1);
		}
		else
		{
			flag = ((t%2)?1:0);
		}
		if(!flag)
			break;
		i--;
		n /= 10;
	}
	if(n == 0 && s[ls-1] == 0)
		flag = 1;
	return flag;
}
int main()
{
	int t;
	cin >> t;
	multiset<ll> my;
	while(t--)
	{
		char c;
		ll x;
		string s;
		cin >> c;
		ll count = 0;
		if(c == '+')
		{
			cin >> x;
			my.insert(x);
		}
		else if(c == '-')
		{
			cin >> x;
			multiset<ll>::iterator it = my.find(x);
			my.erase(it);
		}
		else
		{
			cin >> s;
			multiset<ll>::iterator it = my.begin();
			for(;it != my.end(); it++)
			{
				if(check(*it,s))
					count++;
			}
			cout << count << endl;
		}
	}
  	return 0;
}
