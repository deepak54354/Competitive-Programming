#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-6
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
double n,h,b = 1;
/*int binaryS(double left, double right, double area)
{
  while(left-right <= eps)
  {
    double mid = (left+right)/2;
    double area1 = (0.5)*(mid-left)*(mid+left)*(b/h);
    cout << area1 << endl;
    if(area-area1 <= eps){
      return mid;
    }
    if(area1-area < -1*eps)
      left = mid+mid/2;
    else
      right = mid-mid/2;
  }
}*/
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> h;
	FOR(i,1,n-1)
	{
		double h1 = (sqrt(double(i)/double(n)))*h;
		cout << fixed << setprecision(12) << h1 << " ";
	}
	cout << endl;
	return 0;
}