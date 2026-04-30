#include <stdio.h>
#include <stdlib.h>

int m,n,a,head,tail,s[1000];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n-1;i++) s[i]=i+1;
    for(int j=0;j<n;j++){
        for(int i=0;i<m-1;i++){
            s[tail]=s[head];
            tail=(tail+1)%n;
            head=(head+1)%n;
        }
        printf("%d ",s[head]);
        head=(head+1)%n;
    }
    printf("\n");
    return 0;
}
