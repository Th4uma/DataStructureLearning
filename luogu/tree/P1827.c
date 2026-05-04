#include <stdio.h>
#include <stdlib.h>

int n,x;
char middle[1000001],front[1000001];

void dfs(int zl,int zr,int ql,int qr){
    int m;
    for(int i=zl;i<=zr;i++){
        if(middle[i]==front[ql]) m=i;
    }
    if(m>zl) dfs(zl,m-1,ql+1,ql+m-zl);
    if(m<zr) dfs(m+1,zr,ql+m-zl+1,qr);
    printf("%c",front[ql]);
}

int main(){
    scanf("%s%s",middle,front);
    while(front[x]>='A'&&front[x]<='Z') x++;
    dfs(0,x-1,0,x-1);
    printf("\n");
    return 0;
}
