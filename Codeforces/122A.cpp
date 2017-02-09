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
bool islucky(int number)
{
	bool flag = true;
	while(number)
	{
		int temp = number%10;
		if(temp != 4 && temp != 7)
		{
			flag = false;
			break;
		}
		number /= 10;
	}
	return flag;
}
int main()
{
	int n;
	cin >> n;
	FOR(i,4,n)
	{
		if(islucky(i))
		{
			if(n%i == 0)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	} 
	cout << "NO" << endl;
  	return 0;
}
