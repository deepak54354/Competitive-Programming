#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;
int reverse(int number);
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int m,n;
    cin >> m >> n;
    m = reverse(m);
    n = reverse(n);
    cout<<(reverse(m+n))<<endl;
  }
}

int reverse(int number)
{
  int rev=0;
  while(number > 0)
  {
    rev = (rev*10)+(number%10);
    number/=10;
  }
  return rev;
}
