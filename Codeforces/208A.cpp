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
	string ans ="";
	int n = s.size();
	int i = 0;
	while(i < n)
	{
		if(s.substr(i,3) == "WUB")
		{
			if((i <= 2 && i > 0))
			{
				ans += " ";
			}
			else if(i > 2 && s.substr(i-3,3) != "WUB")
				ans+= " ";
			i += 3; 
		}
		else
		{
			ans += s[i];
			i++;
		} 
	}
	cout << ans << endl;
  	return 0;
}
