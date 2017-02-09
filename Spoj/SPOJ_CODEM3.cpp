#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define MEM(a,val) memset(a,val,sizeof(a))
//Extra
#define pb push_back
#define SS stringstream
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int n;
    cin >> n;
    ll* arr = new ll [n];
    FOR(i,0,n-1)
      cin >> arr[i];
    ll cost = 0;
    int j = n-1;
    FORD(i,0,n-1)
    {
      if(arr[i]==0)
      {
        cost += abs(j-i);
        j--;
      }
    }
    cout << cost << endl;
  }
  return 0;
}
