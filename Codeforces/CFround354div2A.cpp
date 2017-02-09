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
#define REP(dt,i,b) for(dt i = 0; i < b; i++)
#define FOR(dt,i,a,b) for(dt i = a; i < b; i++)
#define REPD(dt,i,b) for(dt i = b; i >= 0; i--)
#define FORD(dt,i,a,b) for(dt i = b; i >= a; i--)

typedef unsigned long long ul;
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  int pos_min,pos_max;
  REP(int,i,N)
  {
    int x;
    cin >> x;
    if(x == 1)
      pos_min = i;
    else if(x == N)
      pos_max = i;
  }
  int max,min;
  max = pos_max;
  min = pos_min;
  if(pos_min > max)
  {
    max = pos_min, min = pos_max;
  }
  int after,before;
  after = N-max-1, before = min;
  if(!after & !before)
    cout << N-1 << endl;
  else
  {
    int max1 = after;
    if(before > after)
    {
      max1 = before;
    }
    cout << abs(max-min) + max1 << endl;
  }
  return 0;
}
