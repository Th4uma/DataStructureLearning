#include <stdio.h>
#include <stdlib.h>

int n,q,ps[100001],pop[100001],push[100001];

int main(){
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&n);
        for(int j=0;j<=n;j++) ps[j]=pop[j]=push[j]=0;
        int top=0,topp=1,y=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&ps[j]);
        }
        for(int j=1;j<=n;j++){
            scanf("%d",&pop[j]);
        }
        for(int j=1;j<=n;j++){
            if(push[top]==pop[j]){
                push[top]=0;
                top--;
                continue;
            }else while(push[top]!=pop[j]&&topp<=n){
                top++;
                push[top]=ps[topp];
                topp++;
            }
            if(push[top]!=pop[j]){
                y=1;
            }else {
                push[top]=0;
                top--;
            }
        }
        if(y==0){
            printf("Yes\n");
        }else printf("No\n"); 
    }
    return 0;
}
