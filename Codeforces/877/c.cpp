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
	cout << (n+n/2) << endl;
	for(int i = 2; i <=n; i+=2) cout << i << " ";
	for(int i = 1; i <=n; i+=2) cout << i << " ";
	for(int i = 2; i<=n; i+=2) cout << i << " ";
	cout << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}