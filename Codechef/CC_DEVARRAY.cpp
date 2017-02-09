#include <iostream>
#define ul unsigned long int
using namespace std;
int main()
{
  int N,Q;
  cin >> N >> Q;
  ul* A = new ul [N];
  ul query;
  ul min, max;
  for(int i = 0; i < N; ++i)
    cin >> A[i];
  min = max = A[0];
  for(int i = 1; i < N; ++i)
  {
    if(A[i] < min)
      min = A[i];
    if(A[i] > max)
      max = A[i];
  }
  for(int i = 0; i < Q; i++)
  {
    cin >> query;
    if(query >=min && query <= max)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
