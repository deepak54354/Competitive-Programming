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
string spell(string number)
{
	int sum = 0;
	FORD(i,0,number.size()-1)
	{
		sum += number[i]-'0';
	}
	return to_string(sum);
}
int main()
{
	string n;
	cin >> n;
	int ans = 0;
	while(n.size() > 1)
	{
		ans++;
		n = spell(n);
	}
	cout << ans << endl;
  	return 0;
}
