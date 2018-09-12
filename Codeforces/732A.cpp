#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int k,r;
	cin >> k >> r;
	int x = 1;
	while(1){
		int j = k*x;
		if((j-r)%10 == 0 or j%10 == 0){
			cout << x << '\n';
			break;
		}
		x++;
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