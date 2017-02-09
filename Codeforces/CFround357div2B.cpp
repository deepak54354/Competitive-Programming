#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  ll a_max,b_max,c_max;
  a_max = n/1234567;
  b_max = n/123456;
  c_max = n/1234;
  for(ll b = 0; b <= b_max; b++)
  {
    for(ll a = 0; a<=a_max; a++)
    {
      ll val = a*1234567 + b*123456;
      if(n >= val && (n-val)%1234 == 0)
        {cout << "YES" << endl;return 0;}
    }
  }
  cout << "NO" << endl;
  return 0;
}
