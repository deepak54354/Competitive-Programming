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

	int l,r;
	l = r = 0;

	int len = s.size();

	int count[2] = {0};

	for(int i = 0; i < len; i++){
		if(s[i] != '.')
			count[s[i]-'A']++;
	}

	while(l < len){
		if(s[l] == '.'){
			l++;
			continue;
		}
		bool flag = false;
		while(r < len){
			if(r <= l) r = l+1;
			if(s[r] == '.'){
				r++;
			}
			else if(s[r]==s[l]){
				flag = true;
				break;
			}
			else break;
		}
		if(flag)
			count[s[l]-'A'] += r-l-1;
		l = r;
	}
	cout << count[0] << " " << count[1] << "\n";
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}