/*
ID: deepak52
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef struct names
{
  string name;
  int initial_money;
  int shares;
  int final_money;
}data;
void accounts(int i,int m, data* arr);
int search(string name, data* arr);
int NP;
int main()
{
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  fin >> NP;
  data *  datas = new data [NP];
  for (int i = 0; i < NP; ++i)
  {
      fin >> datas[i].name;
      datas[i].final_money = 0;
  }
  for (int i = 0; i < NP; ++i)
  {
    string temp;
    fin >> temp;
    int j = search(temp,datas);
    fin >> datas[j].initial_money >> datas[j].shares;
    if (datas[j].shares != 0)
    {
      datas[j].final_money +=((datas[j].initial_money)%(datas[j].shares));
    }
    else
      datas[j].final_money += datas[j].initial_money;
    for (int count = 0; count < datas[j].shares; ++count)
    {
        string name;
        fin >> name;
        int m = search(name,datas);
        accounts(j, m, datas);
    }
  }
  for (int i = 0; i < NP; ++i)
    fout << datas[i].name <<" "<< (datas[i].final_money - datas[i].initial_money) <<endl;
  return 0;
}
void accounts(int i, int m, data* arr)
{
  int share = (arr[i].initial_money)/(arr[i].shares);
  arr[m].final_money += share;
}

int search(string name, data* arr)
{
  for (int i = 0; i < NP; ++i)
  {
    if(!(name.compare(arr[i].name)))
      return i;
  }
  return 0;
}
