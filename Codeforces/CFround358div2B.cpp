#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll mex = 1;
  int N;
  cin >> N;
  ll* arr = new ll [N];
  for(int i = 0; i < N; i++)
    scanf("%I64d", &arr[i]);
  sort(arr,arr+N);
  for(int i = 0; i < N; i++)
  {
    if(arr[i] >= mex)
      mex++;
  }
  cout << mex << endl;
}
