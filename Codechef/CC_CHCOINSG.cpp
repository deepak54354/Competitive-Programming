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
#define REP(dt,i,b) for(dt i = 0; i < b; ++i)
#define FOR(dt,i,a,b) for(dt i = a; i < b; ++i)
#define REPD(dt,i,b) for(dt i = b; i >= 0; --i)
#define FORD(dt,i,a,b) for(dt i = b; i >= a; --i)

typedef unsigned long long ul;
typedef long long ll;

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    ll N;
    cin >> N;
    if(N%6 != 0)
      cout << "Chef" << endl;
    else
      cout << "Misha" << endl;
  }
  return 0;
}
