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
	string s;
	cin >> s;
	int a[4] = {0};
	for(int i = 0; i < n; i++){
		if(s[i] == 'L')
			a[0]++;
		else if(s[i]=='R')
			a[1]++;
		else if(s[i] == 'U')
			a[2]++;
		else 
			a[3]++;
	}
	int ans = 2*min(a[1],a[0]) + 2*min(a[2],a[3]);
	cout << ans << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}