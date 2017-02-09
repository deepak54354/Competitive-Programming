#include <iostream>
using namespace std;
int main()
{
	int t,N,R,G,B,i,j;
	char color;
	cin >> t;
	for (i = 0; i< t; i++)
	{
		cin >> N;
		R = B = G = 0;
		for (j = 0; j < N; j++)
		{
			cin >> color;
			if (color == 'R')
				R++;
			else if(color == 'G')
				G++;
			else
				B++;
		}

		int max = R;
		if (G >= R)
			max = R;
		else if(B >= R)
			max = B;
			cout << N- max<<endl;
	}
	return 0;

}
