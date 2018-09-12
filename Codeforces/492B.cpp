#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n,l;
	cin >> n >> l;
	double v[n];

	for(int i = 0; i< n; i++)
		cin >> v[i];

	sort(v,v+n);

	// for(int i = 0; i< n; i++)
	// 	cout << v[i] << ' ';

	// cout << '\n';


	double ans = 0.0;
	double a = v[0]-0.0;
	double b = (double)l-v[n-1];

	ans = max(a,b);
	if(n == 1){
		cout << ans << '\n';
		return 0;
	}
	
	double mini = (v[1]-v[0])/2.0;

	for(int i = 1; i < n-1; i++){
		mini = max(mini, (v[i+1]-v[i])/2.0);
	}

	// cout << a << ' ' << b << ' ' << mini << '\n';
	cout << fixed << setprecision(12) << max(ans, mini) << '\n';

	return 0;
}