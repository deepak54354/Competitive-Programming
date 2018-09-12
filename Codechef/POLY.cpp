#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin >> n;
	long long y[n][4];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++)
			cin >> y[i][j];
	}

	int q;
	cin >> q;

	while(q--){
		long long ans = 100000000000000000;
		long long t;
		cin >> t;

		long long c;
		for(int i = 0; i < n; i++){
			c = y[i][3];
			for(int j = 2; j >= 0; j--){
				c = c*t + y[i][j];
			}

			ans = min(ans,c);
		}
		cout << ans << '\n';
	}
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}