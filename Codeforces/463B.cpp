#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	int v[n+1];
	v[0] = 0;

	for(int i = 1; i<=n; i++)
		cin >> v[i];

	int mini = v[0]-v[1];
	int sum = v[0]-v[1];

	for(int i = 1; i < n; i++){
		int diff = v[i] - v[i+1];
		sum += diff;
		mini = min(sum, mini);
	}

	if(mini >= 0){
		cout << 0 << '\n';
	}
	else
		cout << -1*mini << '\n';

	return 0;
}