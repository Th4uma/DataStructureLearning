#include <stdio.h>
#include <stdlib.h>

int n,ans,st;
typedef struct node {
    int l,r;
    char data;
}node;
node middle[1000001],behind[1000001];
char middle[1000001],behind[1000001];

void dfs(int a){
    if(a==0) return;
    printf("%c",m[a].data);
    dfs(m[a].l);
    dfs(m[a].r);
}

int main(){
    scanf("%s%s",middle,behind);
    if(i==1) st=s[0]-'a'+1;
        m[s[0]-'a'+1].data=s[0];
        m[s[0]-'a'+1].l=s[1]-'a'+1;
        m[s[0]-'a'+1].r=s[2]-'a'+1;
        if(s[1]=='*') m[s[0]-'a'+1].l=0;
        if(s[2]=='*') m[s[0]-'a'+1].r=0;
    dfs(st);
    printf("\n");
    return 0;
}
