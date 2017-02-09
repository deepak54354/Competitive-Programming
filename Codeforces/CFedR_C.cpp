#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,a,b,p,q,ans = 0;
  cin >> n >> a >> b >> p >> q;
  ll lcm = (a*b)/(__gcd(a,b));
  ans = p*(n/a) + q*(n/b) - min(p,q)*(n/lcm);
  cout << ans << endl;
  return 0;
}
