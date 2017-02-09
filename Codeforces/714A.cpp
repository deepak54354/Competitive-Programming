#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define MEM(a,val) memset(a,val,sizeof(a))
//vector
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
//Extra
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
int main()
{
	ll l1, l2, r1, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	ll maxi,mini;
	maxi = max(l1,l2);
	mini = min(r1,r2);
	ll ans = mini - maxi +1;
	if(mini < maxi)
	{
		cout << "0" << endl;
		return 0;
	}
	if(k <= mini && k >= maxi)
		ans--;
	cout << ans << endl;
  	return 0;
}
