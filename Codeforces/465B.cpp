#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  bool flag = false;
  int index;
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> arr[i];
    if(arr[i] == 1 && !flag)
    {
      index = i;
      flag = true;
    }
  }
  if(!flag)
  {
    cout << ans << endl;
    return 0;
  }
  else
    ans++;
  flag = true;
  for(int i = index+1; i < n; i++)
  {
    if(arr[i] == 1)
    {
      ans++;
      flag = true;
    }
    if(arr[i] == 0)
    {
      if(flag && i != n-1)
      {
        ans++;
        flag = false;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
