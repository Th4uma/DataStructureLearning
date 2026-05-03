#include <stdio.h>
#include <stdlib.h>

int n=1,ans,ni;

typedef struct node {
    int bh,sz;
}node;
node m[1000001];

void dfs(node m[1000001],int fw){
    if(fw==1) return;
    int c=1;
    for(int i=1;i<=fw;i++){
        if(m[c].sz<m[c+1].sz){
            m[i].sz=m[c+1].sz;
            m[i].bh=m[c+1].bh;
        }else{
            m[i].sz=m[c].sz;
            m[i].bh=m[c].bh;
        } 
        c+=2;
    }
    fw/=2;
    dfs(m,fw);
}

int main(){
    scanf("%d",&ni);
    for(int i=1;i<=ni;i++) n*=2;
    for(int i=1;i<=n;i++){
        scanf("%d",&m[i].sz);
        m[i].bh=i;
    }
    dfs(m,n/2);
    if(m[1].sz>m[2].sz) printf("%d\n",m[2].bh);
    else printf("%d\n",m[1].bh);
    
    return 0;
}
