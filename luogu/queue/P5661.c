#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int time;
    int pr;
}node;
int n,head,tail,car,ans,p,t,s;

int main(){
    node k[100001];
    scanf("%d",&n);
    for(int i=0;i<=n;i++) k[i].time=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&car,&p,&t);
        while(t-k[head].time>45&&head!=tail){
            head=(head+1)%n;
        }
        if(head==tail&&t-k[head].time>45){
            k[tail].time=0;
            k[tail].pr=0;  
        }
        if(car==1){
            s=head;
            int found=-1;
            while(s!=(tail+1)%n){
                if(k[s].pr!=0&&k[s].pr>=p){
                    found=s;
                    break;
                }
                s=(s+1)%n;
            }
            if(found>=0){
                k[found].pr=0;
            }else{
                ans+=p;
            }
        }else if(car==0){
            ans+=p;
            tail=(tail+1)%n;
            k[tail].time=t;
            k[tail].pr=p;    
        } 
    }
    printf("%d\n",ans);
    return 0;
}