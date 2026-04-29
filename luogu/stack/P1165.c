#include <stdio.h>
#include <stdlib.h>

int n,q,x,top,max[200001];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&q);
        if(q==0){
            scanf("%d",&x);
            top++;
            if(x>=max[top-1]){
                max[top]=x;
            }else max[top]=max[top-1];
        }else if(q==1&&top!=0){
            top--;
        }else if(q==2){
            if(top==0) printf("0\n");
            else printf("%d\n",max[top]);
        }
    }
    return 0;
}
