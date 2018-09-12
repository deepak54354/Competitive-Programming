#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,n;
	cin >> n >> a;
	a--;
	int v[n];
	for(int i= 0; i < n; i++){
		cin >> v[i];
	}

	int i = a-1, j = a+1, criminals = 0;
	if(v[a])
		criminals++;

	while(i>=0 or j < n){
		if(i >= 0 and j < n){
			if(v[i] and v[j])
				criminals+=2;
		}
		else if(i >= 0){
			criminals += v[i];
		}
		else if(j < n){
			criminals+= v[j];
		}
		i--;j++;
	}
	cout << criminals << '\n';
	return 0;
}