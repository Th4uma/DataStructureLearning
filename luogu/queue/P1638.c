#include <stdio.h>
#include <stdlib.h>

int n,m,head=1,tail=1,nx[1000001],pr[10001],p,x,y,min;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) pr[i]=0;
    for(int j=1;j<=n;j++){
        scanf("%d",&nx[j]);
    }
    while(p<m){
        if(pr[nx[tail]]==0){
            p++;
        }
        pr[nx[tail]]++;
        tail++;
    }
    while(pr[nx[head]]>1){
        pr[nx[head]]--;
        head++;
    }
    min=tail-head-1;
    x=head;
    y=tail-1;
    while(tail<=n){
        pr[nx[tail]]++;
        while(pr[nx[head]]>1){
            pr[nx[head]]--;
            head++;
        }
        if(tail-head<min){
            x=head;
            y=tail;
            min=tail-head;
        }
        tail++;
    }
    printf("%d %d\n",x,y);
    return 0;
}
