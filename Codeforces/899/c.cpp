#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	long long n;
	cin >> n;

	long long sum = n*(n+1)/2;

	long long k = sum/2;

	int ans = sum%2;

	vector<int> v;

	for(int i = n; i >= 1; i--){
		if(i <= k){
			k -= i;
			v.push_back(i);
		}
	}

	cout << ans << '\n';
	cout << v.size() << ' ';
	for(auto i : v){
		cout << i << ' ';
	}
	cout << '\n';

}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}