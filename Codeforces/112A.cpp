#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
int main()
{
	string a,b;
	cin >> a >> b;
	FOR(i,0,a.size()-1)
	{
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
	}
	if(a < b)
		cout << "-1" << endl;
	else if(a == b)
		cout <<"0" << endl;
	else
		cout << "1" << endl;
  	return 0;
}
