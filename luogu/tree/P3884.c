#include <stdio.h>
#include <stdlib.h>

int n,ansd,answ,a,b,x,y,w[1000001],ansjl=1000000000;
typedef struct node {
    int l,r,f;
}node;
node m[1000001];

void dfs(int sy,int d){
    if(sy==0) return;
    if(d>ansd) ansd=d;
    w[d]++;
    dfs(m[sy].l,d+1);
    dfs(m[sy].r,d+1);
}
void dist(int sy,int last,int mb,int jl){
    if(sy==0) return;
    if(sy==mb){
        if(jl<ansjl) ansjl=jl;
        return;
    }
    if(last!=m[sy].l) dist(m[sy].l,sy,mb,jl+1);
    if(last!=m[sy].r) dist(m[sy].r,sy,mb,jl+1);
    if(last!=m[sy].f) dist(m[sy].f,sy,mb,jl+2);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        m[i].l=m[i].r=m[i].f=0;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        m[b].f=a;
        if(m[a].l==0) m[a].l=b;
        else m[a].r=b;
    }
    scanf("%d%d",&x,&y);
    dfs(1,1);
    dist(x,0,y,0);
    for(int i=1;i<=ansd;i++) if(w[i]>answ) answ=w[i];
    printf("%d\n%d\n%d\n",ansd,answ,ansjl);
    return 0;
}
