/*
ID: deepak52
TASK: beads
LANG: C++
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
int NumberofBeads(int m,int N);
string S;int length;
int main()
{
  ofstream fout("beads.out");
  ifstream fin("beads.in");

  int N;
  fin >> N;
  fin >> S;
  string S2 = S;
  S = S + S2;
  length = 2*N;
  int max,bead;
  max = NumberofBeads(N,N);
  for(int i = N+1; i < length; i++)
  {
    bead = NumberofBeads(i,N);
     if(bead>=max)
     {
       max = bead;
     }
  }
  fout << max << endl;
}
int NumberofBeads(int m,int N)
{
  int bead = 1;
  char c='w';
  for(int i = m; ;i=(i+1)%length)
  {
    c=(S[i]!='w')?S[i]:c;
    if((S[(i+1)%length] == S[i]) || (S[(i+1)%length]=='w') || ((S[i]=='w') && (S[i+1]==c)))
      bead++;
    else break;
    if (bead == N)
      return bead;
  }
  int i;
  bool flag =false;
  for( i = m-1;; --i)
  {
    if((S[i] == c)&& c!='w')
    {
      bead++;
      flag = true;
    }
    else break;
    if(bead==N)
      return bead;
  }
  bead++;
  c='w';
  for(int j=flag?i:m-1 ; ; --j)
  {
    c=(S[i]!='w')?S[i]:c;
    if((S[j-1]==S[j])||(S[j-1]=='w')||((S[j]=='w') && S[j-1]==c)|| ((S[j]=='w') && ((j==i)||(j==m))))
      bead++;

    else
      break;
    if(bead == N)
      return bead;
  }
  return bead;
}
