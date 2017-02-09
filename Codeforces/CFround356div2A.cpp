#include <bits/stdc++.h>

using namespace std;

//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)

//pairs
#define ff first
#define ss second
#define mp make_pair

//array
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a,val) memset(a,val,sizeof(a))

//Extra
#define pb push_back
#define SS stringstream
#define Ignore cin.ignore()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

typedef unsigned long long ul;
typedef long long ll;

int main()
{
  int A[5];
  int sum = 0, arr[101] = {0};
  FOR(i,0,5)
  {
    cin >> A[i];
    sum += A[i];
    arr[A[i]]++;
  }
  int max = arr[1]*1, numb = 1;
  FOR(i,0,101)
  {
    if(arr[i] > 1 && (arr[i]*i > max))
    {
      max = arr[i]*i;
      numb = i;
    }
  }
  if(arr[numb] == 1)
  {
    cout << sum << endl;
    return 0;
  }
  else if(arr[numb] <= 3)
    sum -= max;
  else
    sum -= 3*numb;
  cout << sum << endl;
  return 0;
}
