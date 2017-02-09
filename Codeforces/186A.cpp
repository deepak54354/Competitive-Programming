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
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
int main()
{
	fast_io;
	string s,s1;
	cin >> s >> s1;
	int len = s.length();
	int len1 = s1.length();
	if(len1 != len)
	{
		cout << "NO" << endl;
		return 0;
	}
	int count =0;
	string a = "";
	string a1 = "";
	FOR(i,0,len-1)
	{
		if(s[i] != s1[i])
		{
			count++;
			a1 += s1[i];
			a += s[i];
		}
	}	
	reverse(a.begin(),a.end());
	if(!a1.compare(a) && count == 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}