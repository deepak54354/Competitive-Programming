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

ll count(ll num){ //returns length of the string, given by
				  //function (2^[floor(log(base2)(n))+1] - 1)         
	ll x = 1;
	while(num > 1){
		num/=2;
		x*=2;
	}
	return 2*x-1;
}

bool is_one(ll length, ll target, ll num){
	if(num < 2) return num%2;

	if(length+1==2*target){
		return num%2;
	}

	length/=2;
	num/=2;

	if(target>length+1){
		target-=length+1;
	}
	return is_one(length,target,num);
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	ll n,l,r;
	cin >> n >> l >> r;
	int ans = 0;
	ll x = count(n);
	for(ll i = l; i <=r; i++){	
		ans+=is_one(x,i,n);
	}
	cout << ans << endl;
	return 0;
}