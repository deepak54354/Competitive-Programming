#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

void solve(){
	ll n,k;
	cin >> n >> k;
	ll de[] = {1,0,1,2,9};
	ll facn = 1,facd = 1;

	ll ans = 1;
	for(ll i = 1; i <= k; i++){
		ll temp = facn*(n-i+1)*de[i];
		temp /= facd;
		facn *= (n-i+1);
		facd *= (i+1);

		ans += temp;
	}

	cout << ans << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}