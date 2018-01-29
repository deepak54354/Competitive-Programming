#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	long long l,r,n,rez;
	cin >> n >> rez;
	l = 0;
	r = 1000000008;
	vector<int> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	bool flag = true;

	for(int i = 0; i < n-1; i++){
		if(!(v[i] < r and v[i] > l)){
			flag = false;
			break;
		}

		if(v[i] > rez){
			if(v[i+1] >= v[i]){
				flag = false;
				break;
			}
			r = v[i];
		}

		else if(v[i] < rez){
			if(v[i+1] <= v[i]){
				flag = false;
				break;
			}
			l = v[i];
		}
	}
	cout << (flag?"YES":"NO") << "\n";
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}