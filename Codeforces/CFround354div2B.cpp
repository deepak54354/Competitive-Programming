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
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

typedef unsigned long long ul;
typedef long long ll;

int main()
{
  int S,l;
  cin >> l >> S;
  double glasses[11][11] = {0};
  int ans = 0;
  glasses[0][0] = l;
  for(int i = 0; i < l; i ++)
  {
    for(int j = 0; j <= i; j++)
    {
      if(glasses[i][j] >= 1.0)
      {
        glasses[i+1][j] = (glasses[i][j]-1)/2;
        glasses[i+1][j+1] = (glasses[i][j]-1)/2;
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
