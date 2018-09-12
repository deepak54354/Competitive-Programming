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
	int a[n+1];
	for(int i=1; i < n+1; i++) a[i]=i;
	if(n&1){
		for(int i = 1; i < n; i+=2)
			swap(a[i],a[i+1]);
		swap(a[n-1],a[n]);
	}
	else{
		for(int i = 1; i < n+1; i+=2){
			swap(a[i],a[i+1]);
		}
	}
	for(int i = 1; i < n+1; i++) cout << a[i] << " ";
	cout << "\n";
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}