#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 200010;

void solve(){
	vector<int> v(N,0);
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		v[a]=1;
	}
	for(int i = 0; i < N; i++){
		if(v[i]==0){
			if(k>0) k--;
			else{
				cout << i << endl;
				break;
			}
		}
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