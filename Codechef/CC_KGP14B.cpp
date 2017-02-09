#include <bits/stdc++.h>
using namespace std;
//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
//array
#define MEM(a,val) memset(a,val,sizeof(a))
//vector
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
//Extra
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;
int _a,_b;
int number;
int find(char *A, char t, int j)
{
  FOR(i,j+1,_a-1)
  {
    if(A[i] == t)
      return i;
  }
  return -1;
}
int solution(char* A, char* B,int _a, int _b)
{
    FOR(i,0,_b-1)
     {
      int temp = 0;
      if((_a-i) >= number)
        break;
      int t = find(A,B[i],-1);
      for(int j = i+1; j < _b; j++)
      {
        int t1;
        if(t == -1)
        {
          temp++;
        }
        else
          t1 = t;
        t = find(A,B[j],t1);
      }
      if(temp < number)
        number = temp;
    }
    return number;
}
int main()
{
  int t,m = 1;
  cin >> t;
  while(m <= t)
  {
      number = 1000000;
    cin >> _a >> _b;
    char* A = new char [_a];
    char* B = new char [_b];
    FOR(i,0,_a-1)
      cin >> A[i];
    FOR(i,0,_b-1)
      cin >> B[i];
    int ans = max(_a,_b);
    if(_a < _b)
        ans += solution(B,A,_b,_a);
    else
        ans += solution(A,B,_a,_b);
    cout << "Case " << m << ": " << ans << endl;
    m++;
  }
  return 0;
}
