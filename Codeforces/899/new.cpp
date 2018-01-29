#include <bits/stdc++.h>
using namespace std;

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	int n;
	cin >> n;
	int giv[n];

	for(int i = 0; i < n; i++) cin >> giv[i];

	int cycle = 24; bool tf = false;

	for(int i = 0; cycle > 0; cycle--, i++){
		if(i == 12) i = 0;
		if((days[i] == giv[0]) || (i == 1 && giv[0] == 29)){
			bool TF = true;
			for(int j = 1; j < n; j++){
				int x = i+j;
				if(x >= 12) x%=12;
				if(days[x] != giv[j]) TF = false;
				if(x ==1 && giv[j] == 29) TF = true;
				if(!TF) break;
			}
			if(TF) {tf = true; goto END;}
		}
	}
	END :
	if(tf) cout << "YES" << endl;
	else cout << "NO" << endl;
}