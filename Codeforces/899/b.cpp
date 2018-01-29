#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void solve(){
	int n;
	cin >> n;

	int a[n];

	int count29 = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 29)
			count29++;
	}

	if(count29 > 1){
		cout << "NO" << '\n';
		return;
	}

	bool flag;

	for(int i = 0; i < 12; i++){
		flag = true;
		for(int j = 0; j < n; j++){
			int k = (i+j)%12;


			if(k == 1 and (a[j] == 29 or a[j] == 28)){
				flag = true;
			}
			else if(days[k] == a[j]){
				flag = true;
			}
			else{
				flag = false;
				break;
			}
		}
		if(flag == true)
			break;
	}

	cout << (flag?"YES":"NO") << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}