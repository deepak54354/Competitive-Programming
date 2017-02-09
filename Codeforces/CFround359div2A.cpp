#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N;
  ll dis = 0;
  ll ice;
  cin >> N >> ice;
  for(int i = 0; i < N; i++)
  {
    char c;
    ll d;
    cin >> c >> d;
    //cout << c << " " << d << endl;
    if(c == '+')
      ice += d;
    else
    {
      if(ice < d)
        dis++;
      else
        ice -= d;
    }
    //cout << ice <<  " " << dis << endl;
  }
  cout << ice << " " << dis << endl;
  return 0;
}
