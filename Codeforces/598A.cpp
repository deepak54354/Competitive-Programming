#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    ll number,sum = 0;
    cin >> number;
    sum = (number*(number+1))/2;
    ll temp = number;
    int power = 0;
    while(temp > 1)
    {
      temp = temp/2;
      power++;
    }
    power++;
    ll sum_two = pow(2,power) - 1;
    sum -= 2*sum_two;
    cout << sum << endl;
  }
}
