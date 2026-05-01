#include <stdio.h>
#include <stdlib.h>

int n,m,head=1,tail=0,nx[100001],min[100001];

int main(){
    scanf("%d%d",&n,&m);
    for(int j=1;j<=n;j++){
        scanf("%d",&nx[j]);
    }
    for(int i=1;i<=n;i++){
        while(head<=tail&&nx[min[tail]]>nx[i]){
            tail--;
        }
        min[++tail]=i;
        if(min[head]<=i-m) head++;
        if(i>=m) printf("%d\n",nx[min[head]]);
    }
    return 0;
}
