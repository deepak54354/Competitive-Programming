/*
*ID: deepak54354
*Prob: SPOJ_Prime1
*Description: Generate and print prime numbers in given range
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;
void ordinarysieve(int n);
int cnt;
//array for storing prime numbers upto root(N)
int primes[100000];
int main()
{
  int p,s;
  int t;
  cin >> t;
  long long int m,n;
  while(t--)
  {
    cin >> m >> n;
    cnt = 0;
    //boolean array for detecting primes,initially all true
    bool* is_prime = new bool [n-m+1];
    memset(is_prime,true,(n-m+1)*sizeof(bool));
    //storing prime numbers less than root(n) by sieve
    ordinarysieve(n);
    for (int i = 0; i < cnt; ++i)
    {
      s = m/primes[i];
      s = s*primes[i];// s is largest multiple of primes[i] smaller than m
      for (int j = s; j <= n; j += primes[i])
      {
        if(j >= m)
          is_prime[j-m] = false;// crossing of multiples of prime numbers
      }
    }
    for (int i = 0; i < cnt; ++i)
    {
      if(primes[i] >= m && primes[i] <= n)
        cout << primes[i] <<endl;// printing least prime numbers like 2 & 3 if they lie in range
    }
    for(int i = 0; i < (n-m+1); ++i)
    {
      if(is_prime[i] && i+m !=1)
        cout << i+m <<endl;// printing other prime numbers
    }
    cout << endl;
  }
  return 0;
}
void ordinarysieve(int n)
{
  int range = floor(sqrt((double)n));
  bool* arr = new bool [range+1];
  memset(arr,true,(range+1)*sizeof(bool));
  int k = floor(sqrt((double)range));
  for (int i = 2; i <= k; ++i)
  {
    if(arr[i])
    {
      for(int j = i*i; j <= range; j += i)
        arr[j] = false;
    }
  }
  for (int i = 2; i <= range; ++i)
  {
    if(arr[i])
      primes[cnt++] = i;
  }
}
