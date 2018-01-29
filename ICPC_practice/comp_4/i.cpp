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
	int a = min(n,m);
	int b = max(n,m);
	if(a == 0){
		cout << (b%2==0?"abdullah":"hasan") << endl;
	}
	else if(a == 1){
		cout << "hasan" << endl;
	}
	else if(b == 2){
		cout << "abdullah" << endl;
	}
	else{
		long long c = 1ll*(a-2) + 1ll*(b-3);
		cout <<(c%2==0?"hasan":"abdullah") << endl;; 
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