#include <stdio.h>
#include <stdlib.h>

int m,n,q[1001],s,head,tail,ans,y;

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<=n;i++) q[i]=0;
    for(int i=0;i<n;i++){
        scanf("%d",&s);
        y=0;
        for(int j=head;j<=tail;j++){
            if(q[j]==s){
                y++;
            }
        }
        if(y==0){
            ans++;
            if(tail-head+1==m){
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
