#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<pair<long long ,long long> > v;
	for(int i = 0; i < m; i++){
		long long a,b;
		cin >> a >> b;
		v.push_back(make_pair(b,a));
	}

	sort(v.rbegin(), v.rend());

	long long matches = 0;

	for(auto i : v){
		if(n == 0){
			break;
		}
		if(i.second <= n){
			matches += i.second * i.first;
			n -= i.second;
		}
		else{
			matches += n* i.first;
			n = 0;
		}
	}

	cout << matches << '\n';

	return 0;
}