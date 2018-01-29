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
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	vector<vector<int>> x(2,vector<int> (n,0));
	x[0][0]=x[1][0]=1; 
	int res=1;
	/* here x[i][0] contains length of largest zig-zag sequence 
	/ ending at i, such that ending element is greater than previous element.
	/ and x[i][1] contains length of largest zig zag sequence such that
	/ ending element is less than previous element
	/ So the recursion will be: if v[i] > v[j], i > j, x[i][0] = max(x[j][1]+1,x[j][0])
	*/
	for(int i =1; i<n;i++){
		for(int j = 0; j < i; j++){
			if(v[i]>v[j]){
				x[0][i] = max(x[1][j]+1, x[0][j]);
			}
			if(v[i] < v[j]){
				x[1][i]=max(x[0][j]+1, x[1][j]);
			}
		}
		if(res < max(x[0][i],x[1][i])){
			res=max(x[0][i],x[1][i]);
		}	
	}
	cout << res << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}