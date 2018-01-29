#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int N = 100050;
vector<int> dp(N,0);
vector<int> d(N,0);
vector<int> divi[N];

vector<bool> isprime(N,1);

void seive(){
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i < N; i++){
		if(isprime[i]){
			divi[i].push_back(i);
			for(int j = 2*i; j< N; j+=i){
				divi[j].push_back(i);
				isprime[j]= false;
			}
		}
	}
}

void solve(){
	seive();
	int n;
	cin >> n;

	vector<int> v(n);

	bool flag = false;

	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] != 1){
			flag = true;
		}
	}

	if(!flag){
		cout << 1 << endl;
		return;
	}

	for(auto it : v){
		for(auto j : divi[it]){
			dp[it] = max(dp[it],d[j]+1);
		}

		for(auto j : divi[it]){
			d[j] = max(d[j],dp[it]);
		}
	}
	cout << *max_element(all(dp)) << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}