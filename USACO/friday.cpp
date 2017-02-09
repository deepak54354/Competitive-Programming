/*
ID: deepak52
TASK: friday
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int leapyear(int year);
int main()
{
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int days[7]={0};
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int day = 0;
    int year = 1900;
    int N;
    fin >> N;
    for (int count = 0; count < N; count++)
    {
      month[1] = leapyear(year);
      for (int i = 0; i < 12; ++i)
      {
        day = (day+5)%7;
        days[day]++;
        day = (day + month[i]-12)%7;
      }
      year++;
    }
    fout << days[5]<< " " << days[6] <<" ";
    for (int i = 0; i < 5; ++i)
    {
      if (i != 4)
        fout << days[i]<< " ";
      else
        fout << days[i]<< endl;
    }
    return 0;
}
int leapyear(int year)
{
  if (year%4 == 0)
  {
    if (year%100 == 0)
    {
      if (year%400==0)
        return 29;
      else
        return 28;
    }
    else
      return 29;
  }
  return 28;
}
