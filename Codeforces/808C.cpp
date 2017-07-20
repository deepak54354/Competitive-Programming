#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
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
	//fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,w;
	cin >> n >> w;
	vector<pair<int,int> > v(n);
	int sum = 0;
	int final[n-1];
	FOR(i,0,n-1) 
	{
		int f;
		cin >> f;
		v[i] = make_pair(f,i);
		final[i] = ceil(double(f)/2);
		sum += ceil(double(f)/2);
	}
	if(sum > w){
		cout << -1 << endl;
		return 0;
	}
	else if(sum == w){
		FOR(i,0,n-1){
			cout << final[i] << endl;
		}
		return 0;
	}
	w -=sum;
	sort(v.begin(),v.end());
	bool flag = false;
	//cout << w << endl;
	while(w){
		FORD(i,0,n-1){
			if(w>0 && final[v[i].S]<v[i].F)
			{
				//cout << v[i].F << endl;
				final[v[i].S]++;
				w--;
			}
			else 
			{
				if(final[v[i].S] >= v[i].F &&i == n-1)
					flag = true;
				break;
			}
		}
		if(flag) break;
	}
	if(w){
		cout << -1 << endl;
		return 0;
	}
	FOR(i,0,n-1){
		cout << final[i] << " ";
	}
	cout << endl;
	return 0;
}