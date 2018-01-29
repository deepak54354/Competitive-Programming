#include <bits/stdc++.h>

using namespace std;

#define ll long long


#define mod (ll)1e9+7

int main(){
	ios_base::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r", stdin);
		freopen("output.txt","w", stdout);
	#endif

	ll n,k,m,f;
	cin >> n >> k;
	double p,q = 2.0;

	if(k==1){
		cout << n;
		return 0;
	}

	p = log(n)/log(q);
	p+=1;

	m = p;
	f = pow(2,m);
	cout << f-1;
	return 0;
}