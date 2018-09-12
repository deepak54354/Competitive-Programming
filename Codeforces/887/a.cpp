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
	
	int len = s.size();
	int num = 0;
	if(len < 7){
		cout << "no" << endl;
		return;
	}

	int i = len-1;
	for(int j = len-1; j >= 0; j--){
		if(s[j] == '1'){
			i = j;
		}
	}

	for(int j = i+1; j < len; j++){
		if(s[j] == '0')
			num++;
	}
	// cout << len-i << endl;
	if(num < 6){
		cout << "no" << endl;
	}
	else cout << "yes" << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}