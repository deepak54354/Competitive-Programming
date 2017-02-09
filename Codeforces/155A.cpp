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
	int score,n,count = 0;
	int mini,maxi;
	cin >> n;
	cin >> score;
	mini = maxi =  score;
	FOR(i,1,n-1)
	{
		cin >> score;
		if(score < mini)
		{
			count++;
			mini = score;
		}
		else if(score > maxi)
		{
			count++;
			maxi = score;
		}
	}
	cout << count << endl;
  	return 0;
}
