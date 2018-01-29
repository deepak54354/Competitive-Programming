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
	string s;
	cin >> s;
	int a,d;
	a = d = 0;
	for(int i= 0;i < n; i++){
		if(s[i] == 'A')
			a++;
		else if(s[i] == 'D')
			d++;
	}
	if(a == d)
		cout << "Friendship" << '\n';
	else if(a > d)
		cout << "Anton" << '\n';
	else cout << "Danik" << '\n';
}	

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}