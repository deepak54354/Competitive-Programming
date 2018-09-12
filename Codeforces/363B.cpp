#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	long long h[n];
	for(int i = 0; i < n; i++)
		cin >> h[i];

	vector<long long> sum(n-k+1);
	long long ans = 0;
	int ind = 1;

	for(int i = 0;  i < k; i++)
		sum[0] += h[i];

	ans = sum[0];

	for(int i = 1; i <= n-k; i++){
		sum[i] = sum[i-1] + h[i+k-1] - h[i-1];
		ind = (ans>=sum[i])?(i+1):ind;
		ans = min(ans,sum[i]);
	}

	cout << ind << '\n';
	return 0;
}