#include <iostream>
using namespace std;

int main()
{
       int N, Q;
    int k;
    cin >> N >> Q;
    int** arr = new int*[N];
    for (long int i = 0; i < N; i++)
    {
        cin >> k;
        arr[i] = new int[k];
        for (long int j = 0; j < k;j++)
            cin>>arr[i][j];
        /*
        for (long int j = 0; j < k; j++)
            cin >> *(*(arr+i)+j);
            */
        if(!i)
            cout<<arr[0][0]<<endl;
        else
            cout<<arr[1][0]<<' '<<arr[0][0]<<endl;
    }
  //  cout<<sub_arr[0]
  cout<<arr[0][0]<<' '<<arr[1][0]<<endl;
    long int a,b;
    for (long int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        //int ans = ;
        cout << (arr[a])[b]<< endl;
    }
    //cout<<*arr[0][0];
	return 0;
}
