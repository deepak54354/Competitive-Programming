#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,m;
	cin >> n;
	int pos[n+10];

	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		pos[a]=i;
	}

	cin >> m;
	long long vasya = 0, petya = 0;
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		vasya += pos[a]+1;
		petya += n-pos[a];
	}
	cout << vasya << " " << petya <<'\n'; 

	return 0;
}