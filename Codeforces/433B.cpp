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
int main()
{
	fast_io;
	int n;
	cin >> n;
	vector<ll> arr(n),sorted_arr(n),sum(n+1),sorted_sum(n+1);
	ll s= 0;
	FOR(i,0,n-1)
	{
		cin >> arr[i];
		s += arr[i];
	}
	sorted_arr= arr;
	sort(sorted_arr.begin(),sorted_arr.end());
	sum[0] = sorted_sum[0] = s;
	sum[n] = sorted_sum[n] = 0;
	FOR(i,1,n-1)
	{
		sum[i] = sum[i-1] - arr[i-1];
		sorted_sum[i] = sorted_sum[i-1] - sorted_arr[i-1];
	}
	int t;
	cin >> t;
	while(t--)
	{
		int type,l,r;
		cin >> type >> l >> r;
		if(type == 1)
			cout << (sum[l-1]-sum[r]) << endl;
		else
			cout << (sorted_sum[l-1]-sorted_sum[r]) << endl;
	}
  	return 0;
}
