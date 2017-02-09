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
  int a, n;
  cin >> a >> n;
  int* arr = new int [a];
  FOR(i,0,a)
    cin >> arr[i];
  int criminals = arr[n-1];
  int f = n,r = n-2;
  while(f < a || r >= 0)
  {
    if(f < a && r >= 0)
    {
      if(arr[f] && arr[r])
        criminals += arr[f]+arr[r];
      f++,r--;
    }
    else if(f >= a && r >=0)
    {
      criminals += arr[r];
      r--;
    }
    else
    {
      criminals += arr[f];
      f++;
    }
  }
  cout << criminals << endl;
  return 0;
}
