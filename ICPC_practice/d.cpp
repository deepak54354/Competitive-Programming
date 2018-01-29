#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int a[2017][2017];

void solve(){
	int n,x;
	cin >> n >> x;
	int j = 1;
	if(n < x+1){
		cout << -1 << endl;
		return;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < x; j++){
			a[i][j] = i + 1 + j*n;
		}
	}
	for(int j = x; j < 2*x; j++){
		for(int i = 0; i < n; i++){
			int k = j%x + 1;
			a[i][j] = a[(i+k)%n][j%x];
			// cout << i << j << " " << a[i][j] << endl;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2*x; j++){
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}	
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}