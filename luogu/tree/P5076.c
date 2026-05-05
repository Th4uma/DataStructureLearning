#include <stdio.h>
#include <stdlib.h>

int q,op,ct,gen,x,ansq,ansh,anspm;
typedef struct node {
    int l,r,f;
    int data,pm;
}node;
node m[1000001];

int add(int sy,int x){
    if(sy==0){
        ct++;
        m[ct].data=x;
        return ct; 
    }
    if(x<m[sy].data){
        m[sy].l=add(m[sy].l,x);
        m[sy].pm++;
    }
    else if(x>m[sy].data) m[sy].r=add(m[sy].r,x);
    return sy;
}

void qh(int sy,int x){
    if(sy==0) return;
    if(m[sy].data==x){
        ansq=m[m[sy].l].data;
        if(ansq==2147483647) ansq*=-1;
        ansh=m[m[sy].r].data;
        anspm=m[sy].pm+1;
        return;
    }
    if(x<m[sy].data) qh(m[sy].l,x);
    if(x>m[sy].data) qh(m[sy].r,x);
}

int main(){
    scanf("%d",&q);
    for(int i=0;i<=q;i++){
        m[i].l=m[i].r=m[i].f=0;
        m[i].data=2147483647;
    }
    for(int i=1;i<q;i++){
        scanf("%d%d",&op,&x);
        if(op==1){
            qh(gen,x);
            printf("%d\n",anspm);
        }else if(op==2){
            for(int i=1;i<=ct;i++){
                if(m[i].pm==x){
                    printf("%d",m[i].data);
                    break;
                }
            }
        }else if(op==3){
            qh(gen,x);
            printf("%d\n",ansq);
        }else if(op==4){
            qh(gen,x);
            printf("%d\n",ansh);
        }else if(op==5){
            gen=add(gen,x);
        }
    }
    return 0;
}
