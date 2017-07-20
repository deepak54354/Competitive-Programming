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
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

ll mod(ll a, ll b) // calculates a%b, not remainder
{
	ll ans;
	if(b == 0)
		return -1;
	else
	{
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	}
	return ans;
}

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,f;
	cin >> n >> f;
	vector< pair<int,int> > v;
	FOR(i,0,n-1)
	{
		pair<int,int> temp;
		cin >> temp.F >> temp.S;
		v.pb(temp);
	}
	sort(v.begin(),v.end());
	/*FOR(i,0,n-1)
		cout << v[i].F << " " << v[i].S << endl;*/
	int day = 1;
	ll fruit = 0;
	int temp = f;
	while(!v.empty())
	{
		int i = 0;
		while(!v.empty() && day - v[0].F > 1)
		{
			v.erase(v.begin());
		}
		if(v.empty())
			break;
		if(day - v[0].F <= 1 && day - v[0].F >= 0)
		{
			if(v[0].S > temp)
			{
				fruit += temp;
				v[0].S -= temp;
				temp = f;
				day++;
			}
			else if(v[0].S < temp)
			{
				fruit += v[0].S;
				temp -= v[0].S;
				v.erase(v.begin());
			}
			else
			{
				fruit += temp;
				v.erase(v.begin());
				temp = f;
				day++;
			}
		}
		else
		{
			temp = f;
			day++;
		}
		/*int len = v.size();
		cout << endl;
		cout << "Day-->  " << day << endl;
		cout << "Fruit-->  " << fruit << endl;
		FOR(i,0,len-1)
		{
			cout << v[i].F << " " << v[i].S<< endl;
		}
		cout << endl;*/
	}
	cout << fruit << endl;
	return 0;
}