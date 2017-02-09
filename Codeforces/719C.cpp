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

double roundDec(double number, int decimal);

int main()
{
	int n,t;
	cin >> n >> t;
	string grade;
	cin >> grade;
	int decPoint;
	FOR(i,0,n-1)
	{
		if(s[i] == '.')
		{
			decPoint = i;
			break;
		}
	}
	while(t--)
	{
		FOR(i,decPoint+1,s.size()-1)
		{
			if((grade[i]-'0') >= '5')
			{
				if(grade[i-1] == '.')
				{
					int temp = i-2;
					while(grade[temp] == '9')
					{
						grade[temp] = 
					}
				}
			}
		}
	}
	return 0;
}
