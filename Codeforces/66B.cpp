#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int height[n];

	for(int i = 0; i < n; i++)
		cin >> height[i];

	int ans = 0;

	for(int i = 0; i < n; i++){
		int len_a = 0, len_b = 0;
		for(int j = i+1; j < n; j++){
			if(height[j] <= height[j-1])
				len_a++;
			else
				break;
		}
		for(int j = i-1; j >= 0; j--){
			if(height[j] <= height[j+1])
				len_b++;
			else
				break;
		}
		ans = max(ans,len_a + len_b + 1);
	}
	cout << ans << '\n';
}