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
	int c = 0;
	vector<int> h(s.size()+1,0);
	h[0] = 0;
	h[1]=(s[0]=='a'?1:0);
	for(int i = 1; i< s.size(); i++){
		h[i+1]=h[i]+(s[i]=='a'?1:0);
		// cout << h[i+1] << endl;
	}
	int maxim = 0;
	for(int i = 1; i < s.size()+1; i++){
		for(int j = i; j < s.size()+1; j++){
			int curr = 0;
			int n = j-i+1;
			curr = (n-h[j]+h[i-1]) + (h[i]-h[0]) + (h[s.size()]-h[j]);
			maxim = max(curr,maxim);
		}
	}
	cout << maxim << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}