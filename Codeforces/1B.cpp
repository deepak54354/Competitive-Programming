#include <bits/stdc++.h>
using namespace std;

string convert(int C)
{
  string ans = '';
  string z = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
  int temp = C;
  while(temp > 0)
  {
    if(temp%26 == 0)
    {
      ans += 'Z';
      temp = (temp/26) -1;
    }
    else
    {
      int temp1 = temp%26;
      temp = temp/26;

      ans += z[temp1-1];
    }
  }
  return rev(ans.begin(),ans.end());
}
int main()
{

}
