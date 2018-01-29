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
	// k*=2;
	for(int i = 1; i <= n; i++){
		if(k > 0)
			cout << 2*i << " " << 2*i-1 << " ";
		else
			cout << 2*i-1 << " " << 2*i << " ";
		k--;
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