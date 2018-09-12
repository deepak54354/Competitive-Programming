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
	vector<int> v(k+1,-1);
	while(n--){
		int f;
		string s;
		cin >> f >>s;
		if(s =="BROKEN") v[f]=1;
		else v[f] = 0;	
	}

	int s = 2,us = k-1;
	for(int i = 2; i <k; i++){
		if(v[i]==1){
			us = min(us,i-1);
			break;
		}
		else if(v[i]==0){
			s = max(s,i+1);
		}
	}
	cout << s << " " << us << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}