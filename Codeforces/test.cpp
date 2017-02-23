#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	long max = 0, min = 1000000000;
	long a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if(a[i] < min)
			min = a[i];
		
		if(a[i] > max)
			max = a[i];
	}
	
	if(n == 1 || n == 2)
	{
		cout << "0\n";
		return 0;
	}
	
	cout << max << " " << min << endl;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] != max && a[i] != min)
			ans++;
	}
	
	cout << ans << endl;
	return 0;
}