#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int m,s;
	cin >> m >> s;

	if(s==0 and m != 1){
		cout << "-1 -1" << '\n';
		return;
	}
	else if(s==0 and m == 1){
		cout << "0 0" << '\n';
		return;
	}

	if(s/9 == m){
		if(s%9 != 0){
			cout << "-1 -1" << '\n';
			return;
		}

		for(int i = 0; i < m; i++)
			cout << 9;

		cout << ' ';

		for(int i = 0; i < s/9; i++)
			cout << 9;

		cout << '\n';
	}
	else if(s/9 + 1 == m){
		cout << s%9;
		for(int i = 1; i < m; i++){
			cout << 9;
		}

		cout << ' ';

		for(int i = 0; i < m-1; i++)
			cout <<9;

		cout << s%9 << '\n';
	} 
	else if(s/9 > m){
		cout << "-1 -1" << '\n';
	}
	else{
		int k = s%9;
		int j = s/9;

		if(k == 0){
			k = (k-1+9)%9;

			cout << 1;
			for(int i = 0; i < m-j-1; i++){
				cout << 0;
			}
			
			cout << k;

			for(int i = 0; i < j-1; i++)
				cout << 9;
		}

		else
		{
			cout << 1;
			for(int i = 0; i < m - j - 2; i++){
				cout << 0;
			}
			cout << k-1;
			for(int i = 0; i < j; i++){
				cout << 9;
			}
		}

		cout << ' ';

		for(int i = 0; i < s/9; i++){
			cout << 9;
		}
		cout << s%9;
		for(int i = 0; i < m-s/9-1; i++)
			cout << 0;
		cout << '\n';
	}
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}