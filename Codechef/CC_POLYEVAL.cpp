#include <bits/stdc++.h>
using namespace std;
#define M 786433
typedef long long ll;
/*ll fast_exp(ll base,ll n)
{
  ll ans = 1;
  while(n)
  {
    if(n%2==1)
      ans = (ans*base)%M;

    base = (base*base)%M;
    n = n>>1;
  }
  return ans%M;
}*/

int main()
{
  int N;
  cin >> N;
  int* coeff = new int [N+1];
  for(int i = 0; i < N+1; i++)
    scanf("%d", &coeff[i]);
  int Q;
  cin >> Q;
  while(Q--)
  {
    int x;
    scanf("%d", &x);
    ll ans = coeff[N]%M;
    for(int i = N-1; i >=0; i--)
    {
      ans = (ans*x + coeff[i])%M;
    }
    cout << ans%M << endl;
  }
  return 0;
}
