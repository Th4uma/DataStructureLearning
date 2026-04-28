#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
int n,a,c;

int main(){
    scanf("%d",&n);
    node *b[1000001];
    for(int i=0;i<=n;i++) b[i]=NULL;

    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==0){
            continue;
        }
        if(b[i]==NULL){
            node *new=(node*)malloc(sizeof(node));
            b[i]=new;
            new->next=NULL;
        }
        if(b[a]==NULL){
            node *new=(node*)malloc(sizeof(node));
            b[a]=new;
            new->next=NULL;
        }
        b[i]->data=i;
        b[a]->data=a;
        b[i]->next=b[a];
    }

    scanf("%d",&c);
    node *pr=b[c];
    while(pr!=NULL){
        printf("%d ",pr->data);
        pr=pr->next;
    }
    printf("\n");
    return 0;
}
