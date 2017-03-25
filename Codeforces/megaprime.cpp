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

bool megaPri(ll n){
	while(n){
		int temp = n%10;
		n/=10;
		if(temp!=2&&temp!=3&&temp!=5&&temp!=7)
			return false;
	}
	return true;
}

bool isPrime(ll n){
	if(n<=1) return false;
	if(n<=3) return true;
	if(!(n%2 && n%3)) return false;
	ll c = floor(sqrt(n))+1;
	for(ll i = 5; i<=c; i+=6){
		if(!(n%i && n%(i+2))) return false;
	}
	return true;
}
int main()
{
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--){
		ll first,last;
		cin >> first >> last;
		ll count = 0;
		if(first ==1 || first ==2) count+=2;
		else if(first==3) count++;
		ll i = (first+6+1)/6;
		for(i;6*i+1<=last;i++){
			if(megaPri(6*i+1) && isPrime(6*i+1)){
				//cout << "Eureka!! " << 6*i+1<< endl;
				count++;
			}
			if(megaPri(6*i-1)&&isPrime(6*i-1)){
				//cout << "Eureka!! " << 6*i-1<< endl;
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}