#include <stdio.h>
int main(){int T=10;char c;while(T--){int k=1;while((c=getchar())>'@')k*=(c=='T'||c=='D'||c=='L'||c=='F')?2:1;printf("%d\n",k);}return 0;}
