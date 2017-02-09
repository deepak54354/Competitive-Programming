#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n,d;
  cin >> n >> d;
  int max = 0;
  bool flag = false;
  bool flag_last = false;
  int ans = 0;
  while(d--)
  {
    flag = false;
    string opp;
    cin >> opp;
    for(int i = 0; i < n; i++)
    {
      if(opp[i] == '0')
      {
        flag = true;
        break;
      }
    }
    if(flag_last && flag)
      max++;
    else if(flag && !flag_last)
      max = 1;
    else
      max = 0;
    if(max > ans)
      ans = max;
    flag_last = flag;
  }
  cout << ans << endl;
return 0;
}
