#include <stdio.h>
#include <stdlib.h>

int n,k,p,m,x;
typedef struct node{
    int l,r;
}node;
int main(){
    node a[100001];
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        a[i].l=a[i].r=0;
    }

    int b=1;
    for(int i=2;i<=n;i++){
        scanf("%d%d",&k,&p);
        if(p==0){
            a[i].r=k;
            a[i].l=a[k].l;
            if(a[k].l!=0){
                a[a[k].l].r=i;
            }else b=i;
            a[k].l=i;
        }else if(p==1){
            a[i].l=k;
            a[i].r=a[k].r;
            if(a[k].r!=0){
                a[a[k].r].l=i;
            }
            a[k].r=i;
        }
    }
    
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        if(a[x].l!=0||a[x].r!=0){
            if(a[x].l!=0){
                a[a[x].l].r=a[x].r;
            }
            if(a[x].r!=0){
                a[a[x].r].l=a[x].l;
            }
            if(x==b) b=a[x].r;
            a[x].l=a[x].r=0;
        }
    }

    while(a[b].r!=0){
        printf("%d ",b);
        b=a[b].r;
    }
    printf("%d ",b);
    printf("\n");
    return 0;
}
