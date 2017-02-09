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
ll convert(ll number)
{
	ll ans = 0;
	ll ten = 1;
	while(number)
	{
		if(number%10)
		{
			ans += (number%10)*ten;
			ten *= 10;
		}
		number /= 10;
	}
	return ans;
}
int main()
{
	ll a,b;
	cin >> a >> b;
	ll c = a+b;
	ll A,B,C;
	A = convert(a);
	B = convert(b);
	C = convert(c);
	ll temp = A+B;
	if(C == temp)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
  	return 0;
}
