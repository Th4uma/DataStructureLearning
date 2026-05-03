#include <stdio.h>
#include <stdlib.h>

int n,ans;
typedef struct node {
    int l,r;
}node;
node m[1000001];

void dfs(int a,int d){
    if(a==0) return;
    if(d>ans) ans=d;
    d++;
    dfs(m[a].l,d);
    dfs(m[a].r,d);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&m[i].l,&m[i].r);
    }
    dfs(1,1);
    
    printf("%d\n",ans);
    return 0;
}
