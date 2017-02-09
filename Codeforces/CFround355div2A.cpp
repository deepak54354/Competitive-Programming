#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
using namespace std;
int main()
{
  int n,h;
  cin >> n >> h;
  int height;
  int width = 0;
  for(int i = 0; i < n; ++i)
  {
    cin >> height;
    if(height > h)
      width += 2;
    else
      width++;
  }
  cout << width << endl;
  return 0;
}
