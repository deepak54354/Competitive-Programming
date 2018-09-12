#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,m;
	char c;
	cin >> n >> m >> c;

	string mat[n];

	for(int i = 0; i < n; i++){
		cin >> mat[i];
	}

	set<char> deputy;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == c){
				if(i+1 < n and mat[i+1][j] != c and mat[i+1][j] != '.')
					deputy.insert(mat[i+1][j]);
				if(i-1 >= 0 and mat[i-1][j] != c and mat[i-1][j] != '.')
					deputy.insert(mat[i-1][j]);
				if(j+1 < m and mat[i][j+1] != c and mat[i][j+1] != '.')
					deputy.insert(mat[i][j+1]);
				if(j-1 >= 0 and mat[i][j-1] != c and mat[i][j-1] != '.')
					deputy.insert(mat[i][j-1]);
			}
		}
	}

	// for(auto i : deputy)
	// 	cout << i << ' ';
	// cout << '\n';
	cout << deputy.size() << '\n';
	return 0;
}