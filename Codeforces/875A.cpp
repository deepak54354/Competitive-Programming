#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int sum_dig(ll n){
	int sum = 0;
	while(n){
		sum += n%10;
		n/=10;
	}
	return sum;
}

void solve(){
	int n;
	cin >> n;
	bool flag = false;
	vector<int> ans;
	for(int i = 1; i <= 81; i++){
		if(i == sum_dig(n-i)){
			ans.push_back(n-i);
			flag = true;
		}
	}

	sort(all(ans));
	cout << ans.size() << '\n';
	for(auto i : ans){
		cout << i << '\n';
	}
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}