#include <bits/stdc++.h>

using namespace std;

double roundDec(double number,int decimal)
{
  int y = number;
  double z = number-y;
  int q = pow(10,decimal);
  double m = q*z;
  cout << "m = " << m << endl;
  double p = round(m);
  cout << "p = " << p << endl;
  double ans = (double)(y)+(1.0/q)*p;

  return ans;
}


int main()
{ 
  double r;
  cin >> r ;
  r = roundDec(r,2);
  cout << r << endl;
  return 0;

}
