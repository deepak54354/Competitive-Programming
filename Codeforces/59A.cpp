#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	string s;
	cin >> s;
	int up=0,low=0;
	for(auto i : s){
		if(isupper(i)) up++;
		else low++;
	}
	string ans = "";
	if(up>low){
		for(auto i:s){
			ans += toupper(i);
		}
	}
	else{
		for(auto i : s){
			ans += tolower(i);
		}
	}
	cout << ans << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}