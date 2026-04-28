#include <stdio.h>
#include <stdlib.h>

int m,n,s;
int a[2000001];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&s);
        printf("%d\n",a[s]);
    }
    return 0;
}
