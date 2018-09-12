#include <bits/stdc++.h>

using namespace std;

int main(){

	string s;
	cin >> s;
	int count = 0;
	long long sum = 0;
	if(s.size()==1){
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0; i < s.size(); i++){
		sum += (s[i]-'0');
	}
	count++;

	while(sum >= 10){
		long long temp = sum;
		sum = 0;
		while(temp){
			sum += temp%10;
			temp /= 10;
		}
		count++;
	}

	cout << count << '\n';
	return 0;
}