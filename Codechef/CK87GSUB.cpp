#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	string s;
	cin >> s;
	long long l = 0,r = 1;
	long long n = s.size();
	long long final = 0;
	while(l < n){
		r = l+1;
		while(r < n){
			if(s[r] == s[l])
				r++;
			else break;
		}
		long long len = (r-l);
		final += 1ll*(len*(len-1))/2;
		if(l > 0 and r <= n-1 and s[l-1]==s[r])
			final++;
		l = r;
	}
	cout << final << endl;
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}