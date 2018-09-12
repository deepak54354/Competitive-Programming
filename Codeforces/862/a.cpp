#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> v(110,0);
	while(n--){
		int a;
		cin >> a;
		v[a]++;
	}
	int ans = 0;
	for(int i = 0; i <k; i++){
		if(v[i]==0) ans++;
	}
	ans += v[k];
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