#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int k;
	cin >> k;
	if(k==0) cout << "a";
	for(int i = 0; i < 26 and k>0; i++){
		long long cnt = 1;
		while(cnt*(cnt+1)/2 <= k) cnt++;
		k -= (cnt-1)*(cnt)/2;
		for(int j = 0; j < cnt; j++) cout << char('a'+i);
	}
	cout << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}