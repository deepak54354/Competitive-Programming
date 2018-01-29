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

	int num1,num2;
	num1 = num2 = 0;

	for(int i = 0; i < n; i++){
		int j;
		cin >> j;
		if(j == 1)
			num1++;
		else
			num2++;
	}

	int ans = min(num2,num1);
	num2-=ans;
	num1-= ans;

	ans += num1/3;

	cout << ans << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}