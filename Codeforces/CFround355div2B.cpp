#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <cctype>
#define ll long long
using namespace std;

int main()
{
  ll n,h,k,h_in_mixer,seconds,height;
  h_in_mixer = 0;
  seconds = 0;
  cin >> n >> h >> k;
  for(ll i = 0; i < n; ++i)
  {
    cin >> height;
    if(h_in_mixer + height <= h)
      h_in_mixer += height;
    else
      seconds++,h_in_mixer = height;

    seconds += h_in_mixer/k;
    h_in_mixer %= k;
  }
  seconds += h_in_mixer/k;
  h_in_mixer %= k;
  if(h_in_mixer > 0)
    seconds++;
  cout << seconds << endl;
  return 0;
}
