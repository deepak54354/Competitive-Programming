#include <bits/stdc++.h>

using namespace std;
#define M 2123456
int a[M];
int ans[M];
vector<bool> vis(M);
int n;
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		fill(vis.begin(), vis.end(), 0);
		int outl = n;
		for(int i=n;i>=1, outl>=1;i--){
			ans[i] = outl -a[i];
			vis[ans[i]] = 1;
			while(vis[outl]) outl--;
		}
		for(int i=1;i<=n;i++) cout << ans[i] <<" \n"[i==n];
	}
	return 0;
}