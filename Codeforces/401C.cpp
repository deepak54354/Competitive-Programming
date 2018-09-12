#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int one,zero1;
	cin >> zero1 >> one;

	vector<string> v(zero1+1,"");

	for(int i = 1; i < zero1; i++){
		if(one > 0){
			v[i] += '1';
			one--;
		}
		else{
			cout << "-1\n";
			return;
		}
	}
	for(int i = 1; i < zero1; i++){
		if(one > 0){
			v[i]+='1';
			one--;
		}
	}

	if(one > 4){
		cout << "-1\n";
		return;
	}
	else{
		for(int i = 0; i < 2 and one > 0; i++){
			v[0] += '1';
			one--;
		} 

		for(int i = 0; i < 2 and one > 0; i++){
			v[zero1] += '1';
			one--;
		}
	}
	for(int i = 0; i < zero1+1; i++){
		if(i != zero1)
			cout << v[i] << '0';
		else
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