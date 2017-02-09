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
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

typedef unsigned long long ul;
typedef long long ll;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    ll k;
    cin >> k;
    k-=1;
    ll magic = 0;
    vector <int> final;
    while(k)
    {
      final.pb(k%5);
      k /= 5;
    }

    FORD(i,0,final.size()-1)
    {
      magic = magic*10 + final[i];
    }
    magic *= 2;
    cout << magic << endl;
  }
  return 0;
}
