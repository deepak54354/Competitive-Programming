// C++ program to print print all primes smaller than
// n using segmented sieve
#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

ll mod(ll a, ll b) // calculates a%b, not remainder
{
  ll ans;
  if(b == 0)
    return -1;
  else
  {
    ans = (a<0 ? mod(((a%b)+b),b) : a%b);
  }
  return ans;
}

vector<int> prime;
vector<int> prime1;
void simpleSieve(int limit)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    vector<bool> mark(limit+1,true);

    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
}

void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    simpleSieve(limit); 

    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low  = limit;
    int high = 2*limit;

    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        vector<bool> mark(limit+1,true);

        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            /*  Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100]  marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range  */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                prime1.push_back(i);

        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}

bool megaPrime(long long n){
    while(n){
        int temp = n%10;
        n/=10;
        if(temp!=2&&temp!=3&&temp!=5&&temp!=7) return false;
    }
    return true;
}
int main(){
    long first;
    long last;
    cin >> first >> last;
    // your code goes here
    long c = floor(sqrt(last))+1;
    segmentedSieve(c);
    prime.insert(prime.end(),prime1.begin(),prime1.end());
    long size = prime.size();
    vector<bool> finale(last-first+10,true);
    int count = 0;
    if(first == 1) finale[0] = false;
    for(int i = 0; i < size; i++){
       long val = prime[i];
       long j=(first+val+1)/val;
       j=(j)*val;
       if(j-val >=first) j-=val;
       if(j == val) j+=val;
       for(j; j<=last; j+=val){
           //cout << "O yeah!! " << j << endl; 
           finale[j-first]=false;
       }       
    }
    for(long i = first; i <=last;i++){
        if(finale[i-first]){
            //cout << "O Yeah!! " << i << endl; 
            if(megaPrime(i)){
                //cout << "Eureka!!" << endl;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
