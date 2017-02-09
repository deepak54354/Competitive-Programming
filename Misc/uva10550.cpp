#include <bits/stdc++.h>
using namespace std;
int main()
{
    int start, code[3];
    scanf("%d %d %d %d", &start, &code[0], &code[1], &code[2]);;
    while(start || code[0] || code[1] || code[2])
    {
        int value = 1080 + ((start - code[0] + 40)%40 + (code[1] - code[0] + 40)%40 + (code[1] - code[2] + 40)%40)*9;
        printf("%d\n", value);
        scanf("%d %d %d %d", &start, &code[0], &code[1], &code[2]);
    }
}
