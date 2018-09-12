#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	string s;
	string t;

	cin >> s >> t;
	int i = 0;
	for(int j = 0; j < t.size(); j++){
		if(t[j] == s[i] and i < s.size())
			i++;
	}

	cout << i+1 << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}