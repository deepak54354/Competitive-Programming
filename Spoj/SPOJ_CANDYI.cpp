#include <iostream>
using namespace std;
int main()
{
  while(1)
  {
    int c;
    cin >> c;
    if (c!=-1)
    {
      int sum=0,result = 0;
      int* arr = new int[c];
      for(int i = 0; i<c; ++i)
      {
        cin >> arr[i];
        sum += arr[i];
      }
      if(sum%c)
        cout << "-1"<<endl;
      else
      {
        int temp = sum/c;
        for (int i = 0; i < c; ++i)
        {
          if(temp > arr[i])
            result += (temp - arr[i]);
        }
        cout << result<<endl;
      }
    }
    else
      return 0;
  }
}
