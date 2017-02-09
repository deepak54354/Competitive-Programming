#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define MEM(a,val) memset(a,val,sizeof(a))
//vector
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
//Extra
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
int main()
{
	int N;
	cin >> N;
	vi A(N);
	FOR(i,0,N-1)
		cin >> A[i];
	ll y,x;
	sort(A.begin(),A.end());
	y = A[0];
	int j = 0;
	FOR(i,1,N-1)
	{
		if(A[i] > y)
		{
			x = A[i] - y;
			y = A[i];
			j = i;	
			break;
		}
	}
	if(j == 0 || j == N-1)
	{
		cout << "YES" << endl;
		return 0;
	}
	bool flag = 0;
	FOR(i,j+1,N-1)
	{
		if(A[i] > y && abs(A[i]-y) != x)
		{
			flag = 0;
			break;
		} 
		else if(A[i] > y && abs(A[i] -y) == x)
			flag = 1;
		else
			flag = 1;

	}
	cout << (flag?"YES":"NO") << endl;
  	return 0;
}
