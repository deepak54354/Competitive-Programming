#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n, k;
	cin >> n >> k;
	unordered_map<int,int> m;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
		m[v[i]]++;
	}
	long long ans = 0;
	for(int i = 0; i < n; i++){
		int j = v[i]+k;
		ans += m[j]*m[v[i]];
		//cout << j << " " << i << '\n';
	}
	cout << ans<< "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}