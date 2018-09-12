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
	int po = 0;

	int ans = 0;
	for(int i = 0; i < n; i++){
		int j;
		cin >> j;

		if(j!=-1)
			po+=j;
		else if(po == 0)
			ans += 1;
		else
			po--;
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