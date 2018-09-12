#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,m;
	cin >> n >> m;

	int reach = 0;

	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		if(i == 0 and a !=0){
			cout << "NO" << '\n';
			return;
		}

		if(reach >= a){
			reach = max(reach,b);
		}

		if(reach >= m and a <= m){
			cout << "YES" << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
	return;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}