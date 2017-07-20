#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9+7)
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
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i > a; i--)
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
ll fast_exp(ll base,ll n)
{
  ll ans = 1;
  while(n)
  {
    if(n%2==1)
      ans = (ans*base)%MAX;

    base = (base*base)%MAX;
    n = n>>1;
  }
  return ans%MAX;
}
int randomise(){
	return (rand()%(MAX+1));
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n;//=300000;
	//srand(time(NULL));
	cin >> n;
	vector<ll> v(n);
	FOR(i,0,n){
		cin >> v[i];
	}
	//generate(v.begin(),v.end(),randomise);
	ll exp[n+1];
	exp[0] = 1;
	FOR(i,1,n+1){
		exp[i] = fast_exp(2,i);
	}
	sort(v.rbegin(),v.rend());
	ll sum = 0;
	FOR(i,0,n){
		sum = (sum + ((v[i]%MAX)*((exp[n-i-1]-exp[i]))%MAX)%MAX)%MAX;
		sum = mod(sum,MAX);
	}
	cout << sum << endl;
	return 0;
}