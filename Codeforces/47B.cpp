#include <bits/stdc++.h>

using namespace std;

int main(){

	string s[3];
	char ans[3] = {'0', '0', '0'};
	int v[3] = {0};

	cin >> s[0] >> s[1] >> s[2];

	for(int i = 0; i < 3; i++){
		if(s[i][1] == '<'){
			v[s[i][2]-'A']++;
		}
		else{
			v[s[i][0]-'A']++;
		}
	}

	for(int i = 0; i < 3; i++){
		if(ans[v[i]] != '0'){
			cout << "Impossible\n";
			return 0;
		}
		else{
			ans[v[i]] = i+'A';
		}
	}

	cout << ans[0] << ans[1] << ans[2] << '\n';
	return 0;
}