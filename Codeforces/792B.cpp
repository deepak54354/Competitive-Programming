#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
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

int mod(int a, int b) // calculates a%b, not remainder
{
	int ans;
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
	int n,k;
	cin >> n >> k;
	vi v(n);
	FOR(i,0,n-1) v[i] = i+1;
	int lead = 0;
	FOR(i,0,k-1){
		int a;
		cin >> a;
		//bool flag = false;
		if(n-1-lead >= a){
			cout << v[(lead+a)%n] << " ";
			v.erase(v.begin()+lead+a);
			n = v.size();
			lead = (lead+a)%n;
			//cout << "Lead " << i << ":- " << lead << endl;
		}
		else 
		{
			a -= (n-1-lead);
			int j = mod(a,n);
			if(j == 0) 
			{
				cout << v[n-1] << " ";
				v.erase(v.begin()+n-1);
				n = v.size();
				lead = 0;
				//cout << "Lead " << i << ":- " << lead << endl; 
				continue;
			}
			cout << v[j-1] << " ";
			v.erase(v.begin()+j-1);
			n = v.size();
			lead = j-1;
			//cout << "Lead " << i << ":- " << lead << endl; 
		}
	}
	return 0;
}