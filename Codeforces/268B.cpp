#include <bits/stdc++.h>

using namespace std;

int press(int total, int rem)
{
    int temp = rem;
    int temp1 = 0;
    if(total != rem);
      temp1 = (rem-1)*(total-rem);
    return (temp + temp1);
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = n; i >0; i--)
    {
        sum += press(n,i);
    }
    cout << sum << endl;
}
