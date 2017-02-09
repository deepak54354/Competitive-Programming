#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define fast_io ios_base::sync_with_stdio(false)
int main()
{
  fast_io;
  int T;
  int n;
  cin >> T;
  while(T--)
  {
    cin >> n;
    bool* arr = new bool[n];
    ll a;
    FOR(i,0,n-1)
    {
      cin >> a;
      if(a < 0)
        arr[i] = 0;
      else
        arr[i] = 1;
    }
    int len[n];
    len[n-1] = 1;
    FOR(i,0,n-2)
    {
      if(len[i-1] == 1 || i == 0)
      {
        int count = 1;
        FOR(j,i+1,n-1)
        {
          if((arr[j]^arr[j-1]))
            count++;
          else
            break;
        }
        len[i] = count;
      }
      else
        len[i] = len[i-1]-1;
    }
    FOR(i,0,n-1)
    {
      if(i != n-1)
        cout << len[i] << " ";
      else
        cout << len[i] << endl;
    }
  }
  return 0;
}
