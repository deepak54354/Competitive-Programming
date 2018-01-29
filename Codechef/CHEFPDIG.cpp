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
	int a[10]={0};
	for(auto i : s){
		a[i-'0']++;
	}
	string ans = "";
	for(int i = 65; i<(65+26); i++){
		int num = i;
		int b = num%10;
		num/=10;
		int c = num%10;
		if(b==c){
			if(a[b]>1) {
				ans+=char(i);
			}
		}
		else if(a[b] and a[c]) ans += char(i);
	}
	cout << ans << "\n";
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}