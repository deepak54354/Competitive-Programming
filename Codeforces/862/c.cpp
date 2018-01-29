#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,k;
	cin >> n >> k;
	int pw = pow(2,17);
	vector<int> v;
	int sub_xor = 0;
	if(n == 1){
		cout << "YES" << "\n";
		cout << k << "\n";
		return;
	}
	else if(n==2){
		if(k==0){
			cout << "NO" << endl;
			return;
		}
		else{
			v.push_back(1);
			v.push_back(k xor 1);
		}
	}
	else{
		for(int i = 1; i <= n-3; i++){
			sub_xor ^= i;
			v.push_back(i);
		}
		if(sub_xor == k){
			int a[]={pw,pw*2,(pw xor (pw*2))};
			v.insert(v.end(),a,a+3);
		}
		else{
			int a[] = {0,pw,pw xor sub_xor xor k};
			v.insert(v.end(),a,a+3);
		}
	}
	cout << "YES" << endl;
	for(auto i : v) cout << i << " ";
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