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

	vector<char> v(n);

	string s;
	cin >> s;

	int k,m;
	k = n/2 - (1-n%2);
	m = n/2;

	if(k == m){
		v[k] = s[0];
		k--;m++;
	}

	else{
		v[k] = s[0];
		v[m] = s[1];
		k--;m++;
	}

	for(int i = 1 + (1-n%2); i < n; i++){
		v[k] = s[i];

		if(i < n){
			v[m] = s[i+1];i++;
		}
		k--;m++;
	}

	for(int i = 0; i < n; i++){
		cout << v[i];
	}

	cout << '\n';

}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}