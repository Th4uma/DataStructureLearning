#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int time;
    int pr;
}node;
int n,head,tail,car,ans,p,t,yh,s,y;

int main(){
    node k[100001];
    scanf("%d",&n);
    for(int i=0;i<=n;i++) k[i].time=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&car,&p,&t);
        while(t-k[head].time>45){
            head=(head+1)%n;
            yh--;
        }
        if(car==1){
            y=0;
            s=head;
            while(k[s].pr<p&&y<=yh&&yh!=0){
                y++;
                s=(s+1)%n;
            }
            if(k[s].pr>p||k[s].pr==p){
                k[s].pr=0;
            }else{
                ans+=p;
            }
        }else if(car==0){
            ans+=p;
            if(yh==0){
                k[tail].time=t;
                k[tail].pr=p;
                yh++;
            }else{
                tail=(tail+1)%n;
                k[tail].time=t;
                k[tail].pr=p;
                yh++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
