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
	int n,k;
	cin >> n >> k;
	vi len(n);
	string s;
	FOR(i,0,n-1)
	{
		cin >>s;
		len[i] = s.size();
	}
	cin >> s;
	int lenpass = s.size();
	sort(len.begin(),len.end());
	int temp = 0;
	ll best,worst;
	best = worst = 0;
	FOR(i,0,n-1)
	{
		if(temp == k)
		{
			best += 5;
			temp = 0;
		}
		if(len[i] == lenpass)
		{
			best++;
			break;
		}
		else
		{
			temp++;
			best++;
		}

	} 
	temp = 0;
	FOR(i,0,n-1)
	{
		if(temp == k)
		{
			worst += 5;
			temp = 0;
		}
		if(len[i] != lenpass)
		{
			temp++;
			worst++;
		}
		else
		{
			worst++;
			temp++;
			if(len[i+1] != len[i])
				break;
		}
	}
	cout << best << " " << worst << endl;
  	return 0;
}
