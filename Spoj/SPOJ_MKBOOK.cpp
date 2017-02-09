#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  int a, b;
  int i =1;
  while(1)
  {
    int arr[10];
    for(int j = 0; j < 10; ++j)
      arr[j]=0;
    cin >> a;
    if(a == 0)
      break;
    cin >> b;
    int max = b,min = a;
    if(a > b)
    {
      max = a;min = b;
    }
    for(int j = min; j <= max; ++j)
    {
      int numb = j;
      while(numb)
      {
        arr[numb%10]++;
        numb /= 10;
      }
    }
    cout << "Case " << i <<":";
    for(int j =0; j < 10; ++j)
      cout << " " << j << ":" << arr[j];
    cout << endl;
    i++;
  }
  return 0;
}
