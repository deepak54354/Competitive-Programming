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
	string s;
	cin >> n >> s;
	int ftos=0,stof=0;
	for(int i = 1; i < n; i++){
		if(s[i] == 'S' and s[i-1] =='F') ftos++;
		else if(s[i]=='F' and s[i-1]=='S') stof++;
	}

	if(stof>ftos) cout << "YES";
	else cout << "NO";
	cout << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}