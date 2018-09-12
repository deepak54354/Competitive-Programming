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
	vector<int> v(n);
	int g = 0;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		g = __gcd(g,v[i]);
		v[i] = v[i]%2;
	}
	if(g > 1){
		cout << "YES" << endl << 0 << endl;
		return;
	}
	int ans = 0;
	int l,r;
	l = r = 0;
	while(l < n){
		if(v[l]==0){
			l++;
			continue;
		}
		while(r < n){
			if(r<l) r=l;
			if(v[r]==1){
				r++;
			}
			else break;
		}
		int len = r-l;
		ans += int(ceil(double(len)/2.0))+len%2;
		l=r;
	}
	cout << "YES" << endl << ans << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}