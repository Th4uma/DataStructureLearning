#include <stdio.h>
#include <stdlib.h>

int n,k,head=0,tail=-1,nx[2000001],max[2000001];

int main(){
    scanf("%d%d",&n,&k);
    for(int j=1;j<=n;j++){
        scanf("%d",&nx[j]);
    }
    for(int i=1;i<=n;i++){
        while(head<=tail&&nx[max[tail]]<nx[i]){
            tail--;
        }
        tail++;
        max[tail]=i;
        if(max[head]<=i-k) head++;
        if(i>=k){
            printf("%d\n",nx[max[head]]);
        }
    }
    return 0;
}
