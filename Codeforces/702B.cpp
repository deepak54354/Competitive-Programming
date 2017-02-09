#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define MEM(a,val) memset(a,val,sizeof(a))
//vector
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
//Extra
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
int main()
{
  ll ans = 0;
  int n;
  cin >> n;
  vi arr(n);
  FOR(i,0,n-1)
  {
    cin >> arr[i];
  }
  int a = *max_element(arr.begin(),arr.end());
  a *= 2;
  int power = 0;
  while(a)
  {
    a /= 2;
    power++;
  }
  FOR(i,1,power)
  {
    int b = pow(2,i);
    FOR(j,0,n-1)
    {
      int rem;
      if(arr[j] > b)
        continue;
      else
        rem = b - arr[j];
      FOR(k,j+1,n-1)
      {
        if(arr[k] == rem)
          ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
