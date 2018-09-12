#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	string colors = "ROYGBIV";
	string ans = "";

	for(int i = 0; i< n/7; i++){
		ans += colors;
	}

	int rem = n%7;
	if(rem == 0)
		ans += "";
	else if(rem == 1)
		ans += "G";
	else if(rem == 2)
		ans += "GB";
	else if(rem == 3)
		ans += "GBI";
	else if(rem == 4)
		ans+= "GBIV";
	else if(rem == 5)
		ans+= "OGBIV";
	else if(rem == 6)
		ans+= "OYGBIV";

	cout << ans << '\n';

}