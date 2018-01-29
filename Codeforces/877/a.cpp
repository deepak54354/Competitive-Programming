#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	string a[] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	string s;
	cin >> s;
	int c = 0;
	int ind;
	for(int i = 0; i < 5; i++){
		if(s.find(a[i]) != string::npos){
			c++;
			ind = i;
		}
	}
	if(c>1){
		cout << "NO" << endl;
		return;
	}
	else{
		int m = a[ind].size();
		int n = s.size();

		int cnt = 0;
		for(int i = 0; i < n-m+1; i++){
			bool flag = 1;
			for(int j = 0; j < m; j++){
				if(s[i+j]!=a[ind][j]){
					flag = false;
				}

			}
			if(flag)cnt++;
		}
		cout << (cnt==1?"YES":"NO") << endl;
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