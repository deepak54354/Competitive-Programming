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
	vector<long long> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	long long ans = 1e9;
	for(int i = 0; i < n; i++){
		ans = min(ans,a[i]+a[n-i-1]);
	}
	cout << ans << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}