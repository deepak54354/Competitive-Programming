#include <iostream>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; i++)
int main()
{
	int m;
	cin >> m;
	while(m--){
		int n,sum = 0;
		cin >> n;
		int arr[n];
		int count= 0;
		FOR(i,0,n-1) cin >> arr[i];
		sort(arr,arr+n);
		FOR(i,0,n-4){
			sum=arr[i];
			FOR(j,i+1,n-3){
				sum+=arr[j];
				FOR(k,j+1,n-2){
					sum+=arr[k];
					FOR(l,k+1,n-1){
						if(sum > arr[l]) count++;
					}
				}
			}
		}
		
	}
}