#include <stdio.h>
#include <stdlib.h>

int n,ans,aaa=1000000000;
typedef struct node {
    int l,r,data,f;
}node;
node m[1000001];

void far(int a,int way,int last){
    if(a==0) return;
    ans+=m[a].data*way;
    if(last!=m[a].l){
        far(m[a].l,way+1,a);
    }
    if(last!=m[a].r){
        far(m[a].r,way+1,a);
    }
    if(last!=m[a].f){
        far(m[a].f,way+1,a);
    }
}

void dfs(int a){
    if(a==0) return;
    ans=0;
    far(a,0,0);
    if(ans<aaa) aaa=ans;
    dfs(m[a].l);
    dfs(m[a].r);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        m[i].data=m[i].l=m[i].r=m[i].f=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&m[i].data,&m[i].l,&m[i].r);
        m[m[i].l].f=m[m[i].r].f=i;
    }
    dfs(1);
    printf("%d\n",aaa);
    return 0;
}
