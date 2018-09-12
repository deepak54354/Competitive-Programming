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
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int i = 0, j = n-1;

	int ser = 0,di = 0;

	while(j-i >= 1){
		if(a[i] > a[j]){
			ser += a[i];
			i++;
		}	
		else{
			ser += a[j];
			j--;
		}	

		if(j-i >= 0){
			if(a[i] > a[j]){
				di += a[i];
				i++;
			}
			else{
				di += a[j];
				j--;
			}
		}
	}
	if(i == j) ser += a[i];

	cout << ser << ' ' << di << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}