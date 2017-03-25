#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define MAXI  int(1e5+10)
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

vector<bool> prime(2*MAXI+1,true);
void sieve(int N)
{
  prime[0]=false;
  prime[1]=false;
  int end = sqrt(N);
  for(int i = 2; i < end; i++)
  {
    if(prime[i])
    {
      for(int j = i*i; j < N; j += i)
        prime[j] = false;
    }
  }
}

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	sieve(2*MAXI);
	int n;
	cin >> n;
	vi v(n,-1);
	int color = 2;
	FOR(i,0,n-1){
		if(prime[i+2]){
			v[i] = 1;
		}
		else v[i] = 2;
	}
	set<int> s;
	FOR(i,0,n-1) s.insert(v[i]);
	cout << s.size() << endl;
	FOR(i,0,n-1) cout << v[i] << " ";
	cout << endl;
	return 0;
}