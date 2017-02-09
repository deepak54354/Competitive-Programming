#include <iostream>
#define ui unsigned int

using namespace std;
ui seq(ui* C, ui* B, ui n, int k);
ui* A;
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int k ;
    cin >> k;
    ui* B = new ui [k];
    ui* C = new ui [k];
    for(int i = 0; i < k; ++i)
      cin >> B[i];
    for(int i = 0; i < k; ++i)
      cin >> C[i];

    ui n;
    cin >> n;
    A = new ui [2*k+1];
    for(int i = 0; i <= 2*k; ++i)
    {
      if(i < k)
      {
        A[i] = B[i];
      }
      else
        A[i]=0;
    }
    seq(C,B,n,k);
    cout << A[k] << endl;
  }
}
ui seq(ui* C, ui* B, ui n,int k)
{
  if(n <= k)
  {
    return A[n];
  }
  for(int i = 1; i >= k; --i)
  {
    A[2*k] += C[n-1-i]*seq(C,B,i,k);
  }
  return A[k];
}
