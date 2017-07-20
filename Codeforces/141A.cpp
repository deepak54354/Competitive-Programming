#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <=b;i++)
#define FORD(i,a,b) for(int i =b; i >= a; i--)
#define ll long long
#define vi vector<int>
#define vll vector<ll>

int main(){
	vi v(26,0);
	vi v2(26,0);
	string a,b,c;
	cin >> a >> b >>c;
	int i,j;
	FOR(i,0,a.size()-1)
		v[a[i]-'A']++;
	FOR(i,0,b.size()-1)
		v[b[i]-'A']++;
	FOR(i,0,c.size()-1)
		v2[c[i]-'A']++;
	FOR(i,0,25)
	{
		if(v[i] != v2[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}