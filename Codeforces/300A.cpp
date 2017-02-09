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
	vi pos,neg,zero;
	int in;
	FOR(i,0,n-1)
	{
		cin >> in;
		if(in > 0)
			pos.pb(in);
		else if(in == 0)
			zero.pb(in);
		else
			neg.pb(in);
	}
	int len = neg.size();
	if(len%2 == 0)
	{
		zero.pb(neg[len -1]);
		neg.pop_back();
	}
	if(pos.empty())
	{
		pos.pb(*(neg.end()-1));
		pos.pb(*(neg.end()-2));
		neg.pop_back();
		neg.pop_back();
	}
	cout << neg.size() << " ";
	for(vi::iterator it = neg.begin(); it != neg.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << pos.size() << " ";
	for(vi::iterator it = pos.begin(); it != pos.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << zero.size() << " ";
	for(vi::iterator it = zero.begin(); it != zero.end(); it++)
		cout << *it << " ";
	cout << endl;
  	return 0;
}
