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
	ll b,d,s;
	cin >> b >> d >> s;

	ll maxi = max(b,max(d,s));
	ll ans = 0;

	if(maxi == b){
		if(b == s and b == d){
			ans = (b)*3;
		}
		else if(b == s){
			ans = (b-1)*3+2;
		}
		else if(b == d){
			ans = (b-1)*3+2; 
		}
		else{
			ans = (b-1)*3+1;
		}
	} 
	else if(maxi == d){
		if(d == s){
			ans = (d-1)*3+2;
		}
		else{
			ans = (d-2)*3+4;
		}
	}
	else{
		ans = (s-1)*3+1;
	}

	cout << ans - (b+d+s) << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}