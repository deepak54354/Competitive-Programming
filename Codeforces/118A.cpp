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
	string s;
	cin >> s;
	vector<char> myvector;
	FOR(i,0,s.size()-1)
	{
		s[i] = tolower(s[i]);
		if(s[i] != 'a' && s[i] != 'o' && s[i] != 'u' && s[i] != 'y' && s[i] != 'e' && s[i] != 'i')
		{
			myvector.pb('.');
			myvector.pb(s[i]);
		}
	}
	FOR(i,0,myvector.size()-1)
	{
		cout << myvector[i];
	}
	cout << endl;
  	return 0;
}
