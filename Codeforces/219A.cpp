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
	int k;
	string s;
	string ans = "";
	cin >> k;
	cin >> s;
	if(k == 1)
	{
		cout << s << endl;
		return 0;
	}
	int ch[26];
	MEM(ch,0);
	FOR(i,0,s.size()-1)
	{
		ch[s[i]-'a']++;
	}
	FOR(i,0,25)
	{
		if(ch[i] != 0 && ch[i]%k != 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	string temp = "";
	FOR(i,0,25)
	{
		FOR(j,1,ch[i]/k)
		{
			temp += ('a'+i);
		}
	}
	FOR(i,0,k-1)
	{
		ans += temp;
	}
	cout << ans << endl;
  	return 0;
}
