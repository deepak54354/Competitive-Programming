#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,p;
	cin >> n >> p;
	if(p == 1 or n == 2 or p == 2)
		cout << "impossible" << '\n';
	else if(n == 1)
		cout << "a" << '\n';
	else{
		string s = "";
		s += 'a';
		
		for(int i = 0; i < p-2; i++){
			s+='b';
		}

		s+='a';

		// cout << s << '\n';

		int re = n/p;
		string ans = "";
		while(re--){
			ans += s;
		}
		cout << ans << '\n';
	}
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}