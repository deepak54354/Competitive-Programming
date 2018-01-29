#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

unsigned int a = 65536;
void solve(){
	int n;
	cin >> n;
	cout << n << endl;
	for(int i = 0; i < a; i++){
		cout << a << " ";
	}
	for(int i = a; i< n; i++){
		cout << 1 << " ";
	}
	cout << endl;
}

int main(){
	fast_io;
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}