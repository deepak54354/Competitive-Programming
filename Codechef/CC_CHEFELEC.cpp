#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    ll ans = 0;
    ll n;
    cin >> n;
    string village;
    cin >> village;
    ll* x_cor = new ll [n];
    for(int i = 0; i < n; i++)
      cin >> x_cor[i];
    ll left = -1;
    ll right = n+1;
    for(int i = 0; i < n; i++)
    {
      if(village[i] == '1' && i == 0)
      {
        left = 0;
      }
      else if(village[i] == '1')
      {
        right = i;
        if(left != -1)
        {
          ll min = x_cor[right]-x_cor[left+1];
          for(int i = left+1,j=i+1; i < right; i++,j++)
          {
            ll x = ((x_cor[right] - x_cor[j] + x_cor[i]-x_cor[left]));
            if(x < min)
              min = x;
          }
          ans += min;
        }
        else
        {
          ans += x_cor[right]-x_cor[left+1];
        }
        left = right;
      }
      else if(i == n-1 && village[i] == '0')
      {
        ans += (x_cor[n-1]-x_cor[left]);
      }
    }
    cout << ans << endl;
  }
    return 0;
}
