#include <bits/stdc++.h>
using namespace std;
int main()
{
  int stones,a,b;
  bool flag;
  cin >> a >> b >> stones;
  while(1)
  {
    int a_take = __gcd(a,stones);
    if(a_take <= stones)
      stones -= a_take;
    else
    {
      cout << "1" << endl;
      break;
    }
    int b_take = __gcd(b,stones);
    if(b_take <= stones)
      stones -= b_take;
    else
    {
      cout << "0" << endl;
      break;
    }
  }
}
