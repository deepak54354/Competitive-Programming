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
	int cw=0,hard =0;
	for(int i = 0; i < n;i++){
		int a;
		cin >> a;
		if(a >= p/2) cw++;
		else if(a <= p/10) hard++;
	}
	if(cw ==1 and hard == 2) cout << "yes" << "\n";
	else cout << "no" << "\n";
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}