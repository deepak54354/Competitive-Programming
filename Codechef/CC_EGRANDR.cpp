#include <bits/stdc++.h>
using namespace std;
#define eps 1e-9
typedef long long ll;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int average;
    bool fail = false;
    bool full = false;
    int N;
    scanf("%d", &N);
    int temp = N;
    ll sum = 0;
    while(temp--)
    {
      int x;
      scanf("%d", &x);
      if(x <= 2)
        fail = true;
      if(x == 5)
        full = true;
      sum += x;
    }
    average = sum/N;
    if(average >= 4 && full && !fail)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
