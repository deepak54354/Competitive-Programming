#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <=b;i++)
#define FORD(i,a,b) for(int i =b; i >= a; i--)
#define ll long long
#define vi vector<int>
#define vll vector<ll>

int main(){
	int n;
	cin >> n;
	int ans[n];
	FOR(i,0,n-1)
	{
		int a;
		cin >> a;
		ans[a-1] = i+1;
	}
	FOR(i,0,n-1)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}