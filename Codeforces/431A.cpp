#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	long long a[4];
	string s;

	for(int i =0; i < 4; i++)
		cin >> a[i];

	cin >> s;

	long long cal = 0;

	for(auto i : s){
		cal += a[i-'1'];
	}

	cout << cal << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}