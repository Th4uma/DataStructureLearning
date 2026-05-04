#include <stdio.h>
#include <stdlib.h>

int n,x;
char middle[1000001],behind[1000001];

void dfs(int zl,int zr,int hl,int hr){
    int m;
    for(int i=zl;i<=zr;i++){
        if(middle[i]==behind[hr]) m=i;
    }
    printf("%c",behind[hr]);
    if(m>zl) dfs(zl,m-1,hl,hl+m-1-zl);
    if(m<zr) dfs(m+1,zr,hl+m-zl,hr-1);
}

int main(){
    scanf("%s%s",middle,behind);
    while(behind[x]>='A'&&behind[x]<='Z') x++;
    dfs(0,x-1,0,x-1);
    printf("\n");
    return 0;
}
