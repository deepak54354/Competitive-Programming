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
	int ind = (n+k)/2;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(all(v));
	cout << v[ind] << endl;
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}