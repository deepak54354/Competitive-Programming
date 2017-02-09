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
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
#define MAX (int)1e6 + 10
bool prime[MAX];
void sieve(int N)
{
  for(int i = 0; i < N+1; i++)
    prime[i] = true;
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
	sieve(MAX);
	int n;
	cin >> n;
	FOR(i,0,n-1)
	{
		bool flag = false;
		ll x;
		cin >> x;
		double sq = sqrt(x);
		int sq1 = (int)sq;
		//cout << sq1 << endl;
		if((sq-sq1)<= eps)
			if(prime[sq1])
				flag = true;
		cout << (flag?"YES":"NO") << endl;;
	}
  	return 0;
}
