#include <stdio.h>
#include <stdlib.h>

int m,n,q[1001],s,head,tail,ans,y;

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<=n;i++) q[i]=0;
    for(int i=0;i<n;i++){
        scanf("%d",&s);
        y=0;
        for(int i=head;i<=tail;i++){
            if(q[i]==s){
                y++;
            }
        }
        if(y==0){
            ans++;
            if(tail-head==m){
                head++;
                tail++;
                q[tail]=s;
            }else if(head==tail&&q[head]==0){
                q[head]=s;
            }else{
                tail++;
                q[tail]=s;
            }
        } 
    }
    printf("%d\n",ans);
    return 0;
}
