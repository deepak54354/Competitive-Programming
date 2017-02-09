  #include <bits/stdc++.h>
  using namespace std;
  typedef  long long ll;
  bool leap(ll y)
  {
    if((y%4 == 0 && y%100!=0) || y%400 == 0)
      return true;
    else
      return false;
  }
  int main()
  {
    ll y;
    cin >> y;
    ll day = 0;
    ll y1 = y+1;
    while(1)
    {
      if(leap(y1))
        day+=2;
      else
        day++;

      if((day%7 == 0) && leap(y1)==leap(y))
      {
        cout << y1 << endl;
        break;
      }
      y1++;
    }
  }
