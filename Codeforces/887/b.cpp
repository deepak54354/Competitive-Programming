#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int v[3][10];

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			int x;
			cin >> x;
			v[i][x]++;
		}
	}

	int x = 0;
	bool flag = true;
	for(int i = 1; i <= 9; i++){
		if(v[0][i] || v[1][i] || v[2][i]){
			x=i;
		}
		else{
			flag = false;
			break;
		}
	}

	if(!flag){
		cout << x << endl;
		return;
	}

	for(int i = 10; i <= 99; i++){
		int a,b;
		int num = i;
		a = num%10;
		num/=10;
		b = num%10;

		if((v[0][a] and v[1][b]) or (v[0][b] and v[1][a]))
			x = i;
		else if((v[0][a] and v[2][b]) or (v[0][b] and v[2][a]))
			x = i;
		else if((v[1][a] and v[2][b]) or (v[2][a] and v[1][b]))
			x = i;
		else{
			flag = false;
			break;
		}
	}

	if(!flag){
		cout << x << endl;
		return;
	}

	for(int i = 100; i <= 999; i++){
		int num = i;
		int a,b,c;

		a = num%10;
		num/=10;

		b = num%10;
		num/=10;

		c = num%10;
		num/=10;

		if(v[0][a] and v[1][b] and v[2][c])
			x = i;
		else if(v[0][a] and v[1][c] and v[2][b])
			x= i;
		else if(v[0][b] and v[1][a] and v[2][c])
			x = i;
		else if(v[0][b] and v[1][c] and v[2][a])
			x = i;
		else if(v[0][c] and v[1][a] and v[2][b])
			x = i;
		else if(v[0][c] and v[1][b] and v[2][a])
			x = i;
		else{
			flag = false;
			break;
		}
	}

	cout << x << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}