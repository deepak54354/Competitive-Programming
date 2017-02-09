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
int main()
{
  int t;
  cin >> t;
  int i = 1;
  while(i <= t)
  {
    int n;
    cin >> n;
    vi stu(n);
    vi pencil(n);
    FOR(j,0,n-1)
      cin >> stu[j];
    FOR(j,0,n-1)
      cin >> pencil[j];
    sort(stu.begin(),stu.end());
    sort(pencil.begin(),pencil.end());
    ll sum = 0;
    FOR(j,0,n-1)
    {
      sum+= abs(stu[j] - pencil[j]);
    }
    cout << "Case " << i << ": " << sum << endl;
    i++;
  }
  return 0;
}
