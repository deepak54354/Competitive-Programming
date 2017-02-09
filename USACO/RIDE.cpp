/*
ID: deepak52
PROG: ride
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
int convert(string arr);

int main()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string comet; string group;
  fin >> comet >> group;
  int a = convert(comet);
  int b = convert(group);
  if (a==b)
    fout << "GO" << endl;
  else
    fout << "STAY" << endl;
  return 0;
}

int convert(string arr)
{
  int pro = 1;
  for (int i = 0; i < arr.length(); i++)
  {
    pro *=(arr[i]-'A'+1);
  }
  pro = pro%47;
  return pro;
}
