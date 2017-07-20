#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <=b;i++)
#define FORD(i,a,b) for(int i =b; i >= a; i--)
#define ll long long
#define vi vector<int>
#define vll vector<ll>

int main(){
	int n,k,l,c,d,p,nl,np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int drink = k*l;
	int lime = d*c;
	int ans = min(drink/nl, p/np);
	ans = min(ans,lime);
	ans /= n;
	cout << ans << endl;
	return 0;
}