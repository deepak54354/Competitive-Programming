#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a,val) memset(a,val,sizeof(a))
//Extra
#define pb push_back
#define SS stringstream
#define Ignore cin.ignore()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
int prime[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool divisible(int a)
{
  printf("%d \n", a);
  fflush(stdout);
  string response;
  cin >> response;
  if(response == "yes")
    return true;
  return false;
}
int main()
{
  int counter = 0;
  FOR(i,0,15)
  {
      if(divisible(prime[i]))
      {
        counter++;
        if(counter >= 2)
        {
          printf("composite \n");
          return 0;
        }
        if(i < 4 && divisible(SQR(prime[i])))
        {
          printf("composite \n");
          return 0;
        }
        else
        {
          counter++;
          continue;
        }
      }
  }
  printf("prime \n");
  return 0;
}
