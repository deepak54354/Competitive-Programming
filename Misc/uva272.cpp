#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
typedef long long ll;
int main()
{
    char s[MAX];
    ll i,count = 0;
    while(gets(s))
    {
        int l = strlen(s);
        for(i = 0; i < l; i++)
        {
            if(s[i]=='"')
            {
                count++;
                if(count%2==1)
                    printf("``");
                else
                    printf("''");
            }
            else
                printf("%c",s[i]);
        }
        printf("\n");
    }
}
