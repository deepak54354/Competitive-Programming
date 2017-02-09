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
bool isoperator(char a)
{
	return (a == '+' || a== '-' || a== '*' || a=='/' || a=='^');
}
bool hashigherprecedence(char a, char b, map<char,int> chutiya)
{
	return chutiya[a] < chutiya[b];
}
int main()
{
	fast_io;
	map<char,int> chutiya;
	chutiya['+'] = 0;
	chutiya['-'] = 1;
	chutiya['*'] = 2;
	chutiya['/'] = 3;
	chutiya['^'] = 4;
	stack<char> out;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		string ans = "";
		cin >> s;
		FOR(i,0,s.length()-1)
		{
			if(isalpha(s[i]))
			{
				ans += s[i];
			}
			else if(isoperator(s[i]))
			{
				while(!out.empty() && out.top() != '(' && hashigherprecedence(s[i],out.top(),chutiya))
				{
					ans += out.top();
					out.pop();
				}
				out.push(s[i]);
			}
			else if(s[i] == '(')
				out.push(s[i]);
			else if(s[i] == ')')
			{
				while(!out.empty() && out.top() != '(')
				{
					ans += out.top();
					out.pop();
				}
				if(!out.empty()) out.pop();
			}
		}
		while(!out.empty())
		{
			ans += out.top();
			out.pop();
		}
		cout << ans;
		if(t != 0)
			cout << endl; 
	}
	return 0;
}