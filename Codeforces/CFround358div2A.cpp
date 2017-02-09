#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n,m;
  cin >> n >> m;
  ll ans= 0;
  for(int i = 1; i <= n; i++)
  {
    int need = 5-(i%5);
    if(need <= m)
      ans++;
    ans += ((m-need)/5);
    //cout << ans << endl;
  }
  cout << ans << endl;
}
