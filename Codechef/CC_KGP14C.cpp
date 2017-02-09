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
int x, y;
int allot(int n, vector<list <int> > A)
{
  vector<int> array(n,1);
  vector<int> array1(n,1);
  x = 0,y = 0;
  FOR(i,0,n-1)
  {
    if(array[i] == 1)
    {
      for(list<int>::iterator it = A[i].begin(); it != A[i].end();it++)
      {
        array[*it - 1] = -1;
      }
      x++;
      array[i] = 0;
    }
  }
  FOR(i,0,n-1)
  {
    if(array1[i] == 1 && array[i] != 0)
    {
      for(list<int>::iterator it = A[i].begin(); it != A[i].end();it++)
      {
        if(array[*it - 1] == -1)
          return 0;
        array1[*it - 1] = -1;
      }
      y++;
      array[i] = 0;
    }
    else
      array1[i] = -1;
  }
  return 1;
}
int main()
{
  int t;
  cin >> t;
  int m = 1;
  while(m <= t)
  {
    int N;
    cin >> N;
    vector <list<int> > A(N);
    FOR(i,0,N-1)
    {
      int n;
      cin >> n;
      FOR(j,0,n-1)
      {
        int t;
        cin >> t;
        A[i].pb(t);
      }
    }
    bool ans = allot(N,A);
    if(ans == 0)
      x=y=0;
    cout << "Case " << m << ": " << ans <<" " << x <<" " << y << endl;
    m++;
  }
  return 0;
}
