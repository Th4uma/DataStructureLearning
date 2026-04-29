#include <stdio.h>
#include <stdlib.h>

int m,n,a;
typedef struct node{
    int data;
    struct node *next;
}node;

int main(){
    node *head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node *prev=head;

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        node *new=(node*)malloc(sizeof(node));
        new->next=NULL;
        new->data=i;
        prev->next=new;
        prev=new;
    }
    prev->next=head->next;
    node *c=prev->next;
    for(int j=0;j<n;j++){
        for(int i=1;i<m-1;i++){
            c=c->next;
        }
        printf("%d ",c->next->data);
        node *d=c->next;
        c->next=d->next;
        free(d);
        c=c->next;
    }
    printf("\n");
    return 0;
}
