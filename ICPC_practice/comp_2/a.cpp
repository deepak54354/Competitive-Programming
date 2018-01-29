#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string x,y;
vector<vector<int> > a(100,vector<int>(100,-1));

int lcs(int n, int m){
	if(n<=0 or m <=0) return 0;

	if(a[n][m] != -1) return a[n][m];

	if(x[n-1]==y[m-1]){
		a[n][m] = 1+lcs(n-1,m-1);
		return a[n][m];
	}

	else{
		a[n][m] = max(lcs(n-1,m),lcs(n,m-1));
		return a[n][m];
	}
}

void solve(){
	x = "abcdefghijklmnopqrstuvwxyz";
	cin >> y;

	int n = x.size();
	int m = y.size();
	a[0][0] = 0;

	cout << 26-lcs(n,m) << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}