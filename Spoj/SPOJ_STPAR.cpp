#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int t;
  while(cin >> t)
  {
    if(t == 0)
      break;

    int* arr = new int [t];
    int* final = new int [t];
    for(int i = 0; i < t; ++i)
      cin >> arr[i];

    stack<int> wait;
    int j = 0,m = 0;
    while(m<t)
    {
      if(!wait.empty() && j!=0 && wait.top()==final[j-1]+1)
      {
        final[j]=wait.top();
        wait.pop();
        j++;
      }
      else if(m < t-1 && arr[m]>arr[m+1])
      {
        wait.push(arr[m]);
        m++;
      }
      /*else if(arr[m]==1)
      {
        final[0]=1;
        m++;
        j++;
      }*/
      else
      {
        final[j]=arr[m];
        m++;
        j++;
      }

    }
    while(!wait.empty())
    {
      final[j] = wait.top();
      wait.pop();
      j++;
    }
    bool flag=false;
    for(int i = 0; i < t-1; i++)
    {
      if(final[i] < final[i+1])
      {
        flag = true;
        continue;
      }
      flag = false;
      break;
    }
    if(flag)
      cout << "yes"<<endl;
    else
      cout << "no" << endl;
  }
  return 0;
}
