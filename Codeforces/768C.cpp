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
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
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
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,k,x;
	cin >> n >> k >> x;
	vi freq(1025,0);
	vi freq1(1025,0);
	FOR(i,0,n){
		int h;
		cin >> h;
		freq[h]++;
	}
	freq1=freq;
	/*FOR(i,0,16){
		cout << freq[i] << endl;
	}
	cout << endl << endl;*/
	FOR(i,0,k){
		int par = 0;
		FOR(j,0,1025){
			if(freq[j]>0)
			{
				int xo = j^x;
				int change = freq[j]/2;
				if(par==0) change += (freq[j]&1);
				freq1[j]-=change;
				freq1[xo]+=change;
				par ^= (freq[j]&1);

			}
		}
		freq=freq1;
		/*FOR(i,0,16){
			cout << freq[i] << endl;
		}
		cout << endl << endl;*/
	}
	int mini,maxi;
	//cout << freq[0] << endl;
	FOR(i,0,1025){
		if(freq[i] != 0){
			mini = i;
			break;
		}
	}
	FORD(i,mini,1024){
		if(freq[i] > 0){
			maxi = i;
			break;
		}
	}
	cout << maxi <<" "<< mini << endl;
	return 0;
}