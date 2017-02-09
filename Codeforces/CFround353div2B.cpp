#include <bits/stdc++.h>

using namespace std;

//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)

//pairs
#define ff first
#define ss second
#define mp make_pair

//array
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a,val) memset(a,val,sizeof(a))

//Extra
#define pb push_back
#define SS stringstream
#define Ignore cin.ignore()
#define for(i,a,b) for(int i = a; i <= b; i++)
#define ford(i,a,b) for(int i = b; i >= a; i--)

typedef unsigned long long ul;
typedef long long ll;

int main()
{
  ll ans = 0;
  int n,a,b,c,d;
  cin >> n >> a >> b >>c >>d;
  for(x,1,n)
  {
    int y = x + b -c;
    int z = x +a -d;
    int p = y +z -x;
    if(1 <=y && y <= n && 1 <=z && z <= n && 1 <=p && p <= n)
      ans++;
  }
  ans *=n;
  cout << ans << endl;
  return 0;
}
