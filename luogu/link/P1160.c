#include <stdio.h>
#include <stdlib.h>

int n,k,p,m,x;
typedef struct node{
    int data;
    struct node *l;
    struct node *r;
}node;
int main(){
    node *a[100001];
    node *first=(node*)malloc(sizeof(node));
    first->l=NULL;
    first->r=NULL;
    a[1]=first;
    first->data=1;
    node *begin=first;

    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d%d",&k,&p);
        if(p==0){
            node *new=(node*)malloc(sizeof(node));
            new->r=a[k];
            new->l=a[k]->l;
            if(a[k]->l!=NULL){
                a[k]->l->r=new;
            }else begin=new;
            a[k]->l=new;
            a[i]=new;
            new->data=i;
        }else if(p==1){
            node *new=(node*)malloc(sizeof(node));
            new->l=a[k];
            new->r=a[k]->r;
            if(a[k]->r!=NULL){
                a[k]->r->l=new;
            }
            a[k]->r=new;
            a[i]=new;
            new->data=i;
        }
    }
    
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        if(a[x]!=NULL){
            node *d=a[x];
            if(d->l!=NULL){
                d->l->r=d->r;
            }
            if(d->r!=NULL){
                d->r->l=d->l;
            }
            if(d==begin) begin=d->r;
            a[x]=NULL;
            free(d);
        }
    }

    node*p=begin;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->r;
    }
    printf("\n");
    return 0;
}
