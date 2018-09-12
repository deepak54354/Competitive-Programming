#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int prob[7]={0};
	int a[6];
	for(int i =0; i < 6; i++) cin >> a[i];
	for(int i = 0; i< 6; i++){
		int k;
		cin >> k;
		prob[k]++;
	}
	for(int i = 1; i < 7; i++){
		prob[i]+=prob[i-1];
	}
	double probw=0.0,draw=0.0;
	double ans = 0;
	for(int i = 0; i < 6; i++){
		probw += (prob[a[i]-1]/6.0);
	}
	probw/=6.0;
	for(int i = 0; i < 6; i++){
		draw += (prob[a[i]] - prob[(a[i]-1)])/6.0;
	}
	draw/=6.0;
	ans = probw/(1-draw);
	cout << fixed << setprecision(5) <<ans << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}