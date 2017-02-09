#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cycle_length(int N)
{
  ll temp = 0;
  while(1)
  {
    temp++;
    if(N==1)
      break;
    if(N%2==1)
      N=3*N+1;
    else
      N >>= 1;
  }
  return temp;
}
int main()
{
  int i,j;
  while(scanf("%d %d", &i, &j) != EOF)
  {
    int temp_i = i, temp_j = j;
    if(i > j)
      swap(i,j);
      ll max = 0;
      for(int t = i; t <=j; t++)
      {
        ll temp =cycle_length(t);
        if(temp> max)
        max = temp;
      }
      cout << temp_i << " " << temp_j << " "<< max << endl;
  }
  return 0;
}
