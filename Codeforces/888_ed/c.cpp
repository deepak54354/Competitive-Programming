#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n;
string s;

bool check(int k){
	vector<long long> c(26,0);
	for(int i = 0; i < n; i++){
		if(i < k)
			c[s[i]-'a'] += 1ll*(i+1);
		else if(i >= k and i < n-k+1)
			c[s[i]-'a'] += 1ll*k;
		else
			c[s[i]-'a'] += 1ll*(n-i);
	}
	for(int i = 0; i < 26; i++){
		if(c[i] >= n-k+1){
			return true;
		}
	}
	return false;
}

void solve(){
	cin >> s;
	n = s.size();

	int l = 1;
	int r = n;
	
	int mid;
	while(l < r){
		mid = (l+r)/2;

		if(check(mid))
			r = mid;
		else
			l = mid+1;
	}
	
	int ans = r;
	cout << ans << '\n';
}	

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}