#include <iostream>
#include <cmath>

using namespace std;
void Mergesort(unsigned int * A, int p, int r, int way);
void Merge(unsigned int* A, int p, int q, int r, int way);
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    int number;
    cin >> number;
    int way = -1;
    if(!(number%2))
      way = 1;
    unsigned int* amp = new unsigned int [number];
    for(int i = 0; i < number;++i)
      cin >> amp[i];
    Mergesort(amp,0,number-1,way);
    for(int i = 0; i< number; ++i)
      cout << amp[i] << " ";
    cout << endl;
  }
  return 0;
}

void Mergesort(unsigned int * A, int p, int r, int way)
{
  if (p < r)
  {
    int q = (p+r)/2;
    // Sorting the left subarray
    Mergesort(A, p, q, way);
    // Sorting the right subarray
    Mergesort(A, q+1, r, way);
    // Merge sorted lest abd right subarrays
    Merge(A, p ,q, r, way);
  }

  return;
}

void Merge(unsigned int* A, int p, int q, int r, int way)
{
  int n1 = q-p+1;
  int n2 = r-q;
  int* L = new int [n1];
  int* R = new int [n2];
  for(int i = 0; i < n1; ++i)
    L[i]=A[p+i];
  for(int j = 0; j < n2; ++j)
    R[j] = A[q+j+1];
  int i=0,j =0;
  for(int k = p; k <= r; ++k)
  {
    if(way == 1)
    {
      if ((i < n1 && L[i] <= R[j]) || j >= n2)
      {
        A[k]= L[i];
        i++;
      }
      else if(j < n2)
      {
        A[k]=R[j];
        j++;
      }
    }
    else
    {
      if (i < n1 && L[i] >= R[j])
      {
        A[k]= L[i];
        i++;
      }
      else if(j < n2)
      {
        A[k]=R[j];
        j++;
      }
    }
  }
  return;
}
