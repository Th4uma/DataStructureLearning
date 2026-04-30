#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int time;
    int ctry;
}node;
int k,n,head=1,tail=1,t,x,c[100001],ans;

int main(){
    node kk[300001];
    scanf("%d",&n);
    for(int i=0;i<=n;i++) kk[i].time=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&t,&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&x);
            if(head==tail&&kk[head].time==0){
                kk[tail].time=t;
            }else{
                tail++;
                if(tail==300001) tail=1;
                kk[tail].time=t;
            }
            kk[tail].ctry=x;
            if(c[x]==0) ans++;
            c[x]++;
        }

        while(t-kk[head].time>=86400){
            c[kk[head].ctry]--;
            if(c[kk[head].ctry]==0) ans--;
            head++;
            if(head==300001) head=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
