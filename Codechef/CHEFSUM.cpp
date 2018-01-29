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
	int min=1000000000,ind;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a<min){
			min = a;ind = i+1;
		}
	}
	cout << ind << "\n";
}

int main(){
	fast_io;
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}