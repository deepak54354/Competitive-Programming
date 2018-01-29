#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	long long y;
	cin >> y;
	long long ans = 0;
	for(long long b = 1; b <= 700; b++){
		if(y <= b) break;
		ans += floor(sqrt(double(y-b)));
	}
	cout << ans << endl;
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}