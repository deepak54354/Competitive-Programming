#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int a[3];
	for(int i = 0; i < 3; i++) cin >> a[i];
	int i = min_element(a,a+3)-a;
	if(i == 0)
		cout << "First" << endl;
	else if(i == 1)
		cout << "Second" << endl;
	else cout << "Third" << endl;
}
PR
int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}