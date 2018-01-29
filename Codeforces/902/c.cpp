#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

void solve(){
	int n;
	cin >> n;

	int last = 0;

	int a[n];
	bool flag = true;
	for(int i = 0; i <= n ;i++){
		cin >> a[i];

		if(a[i] != 1)
			flag = false;
	}

	if(flag){
		cout << "perfect" << '\n';
		return;
	}
	
	last = n+1;
	for(int i = n; i >=0; i++){
		if(a[i] == 1){
			last = i;
		}	
		else
			break;
	}

	cout << "ambiguous" << '\n';

	ll sum = 0;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j < a[i]; j++){
			cout << sum << ' ';
		}
		sum += a[i];
	}
	cout << '\n';

	sum = 0;

	if(last == n){
		last = n-1;
	}
	else
		last = n;

	for(int i = 0; i <= last-1; i++){
		for(int j = 0; j < a[i]; j++){
			cout << sum << ' ';
		}
		sum += a[i];
	}

	cout << sum << ' ';

	for(int i = 1; i < a[last]; i++)
		cout << sum-1 << ' ';

	sum += a[last];

	for(int i = last+1; i <= n; i++){
		for(int j = 0; j < a[i]; j++){
			cout << sum << ' ';
		}
		sum += a[i];
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