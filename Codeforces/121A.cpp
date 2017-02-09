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
#define all(v) (v).begin(), (v).end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define fast_io ios_base::sync_with_stdio(false)
vector<ll> c;
ll l,r;
void generate(ll x)
{
	if(x>10000000000)
		return;
	if(x >=l) c.pb(x);
	generate(x*10 +4);
	generate(x*10 +7);
	return;
}
int intersection(ll l ,ll r, ll a, ll b)
{
	ll maxi = max(l,a);
	ll mini = min(r,b);
	if(mini < maxi)
		return 0;
	return (mini-maxi+1);
}
int main()
{
	fast_io;
	generate(0);
	int n = c.size();
	sort(all(c));
	cin >> l >> r;
	ll sum = 0;
	FOR(i,1,n-1)
	{
		int count;
		count = intersection(l,r,c[i-1]+1,c[i]);
		sum += (count*c[i]);
	}
	cout << sum << endl;
  	return 0;
}
