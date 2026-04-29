#include <stdio.h>
#include <stdlib.h>

int q,n,s,k;
int *a[100001];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<=n;i++){
        a[i]=NULL;
    }
    for(int i=0;i<q;i++){
        scanf("%d",&s);
        if(s==1){
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            if(a[i]==NULL){
                a[i]=(int*)calloc(100001,sizeof(int));
            }
            a[i][j]=k;
        }else if(s==2){
            int i,j;
            scanf("%d%d",&i,&j);
            printf("%d\n",a[i][j]);
        }
    }
    return 0;
}
